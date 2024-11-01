#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

struct Nodo {
    int distancia, nodo;
    bool operator>(const Nodo &otro) const {
        return distancia > otro.distancia;
    }
};

std::pair<int, std::vector<int>> dijkstra(int n, int origen, int destino, const std::vector<std::vector<std::pair<int, int>>> &grafo) {
    std::vector<int> distancias(n, INF);
    std::vector<int> predecesor(n, -1);  // Almacena el nodo anterior en el camino
    distancias[origen] = 0;

    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        int distancia_actual = pq.top().distancia;
        int nodo_actual = pq.top().nodo;
        pq.pop();

        if (nodo_actual == destino) break;

        if (distancia_actual > distancias[nodo_actual]) continue;

        for (const auto &vecino : grafo[nodo_actual]) {
            int nodo_vecino = vecino.first;
            int peso_arista = vecino.second;

            if (distancias[nodo_actual] + peso_arista < distancias[nodo_vecino]) {
                distancias[nodo_vecino] = distancias[nodo_actual] + peso_arista;
                predecesor[nodo_vecino] = nodo_actual;
                pq.push({distancias[nodo_vecino], nodo_vecino});
            }
        }
    }

    std::vector<int> camino;
    for (int v = destino; v != -1; v = predecesor[v]) {
        camino.push_back(v);
    }
    std::reverse(camino.begin(), camino.end());

    return {distancias[destino], camino};
}

int main() {
    int n = 5;
    std::vector<std::vector<std::pair<int, int>>> grafo(n);

    grafo[0].push_back({1, 10});
    grafo[0].push_back({2, 5});
    grafo[1].push_back({2, 2});
    grafo[1].push_back({3, 1});
    grafo[2].push_back({1, 3});
    grafo[2].push_back({3, 9});
    grafo[3].push_back({4, 4});

    int origen = 0;
    int destino = 4;

    auto resultado = dijkstra(n, origen, destino, grafo);
    int distancia_total = resultado.first;
    std::vector<int> camino = resultado.second;

    if (distancia_total == INF) {
        std::cout << "No hay un camino desde el nodo " << origen << " al nodo " << destino << ".\n";
    } else {
        std::cout << "Camino mas corto desde el nodo " << origen << " al nodo " << destino << ":\n";
        for (size_t i = 0; i < camino.size(); ++i) {
            std::cout << camino[i];
            if (i < camino.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nDistancia total: " << distancia_total << "\n";
    }

    return 0;
}
