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
    std::vector<int> predecesor(n, -1);
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
    int n = 23;
    std::vector<std::vector<std::pair<int, int>>> grafo(n);

    grafo[0].push_back({1, 326});
    grafo[1].push_back({0, 326});

    grafo[1].push_back({2, 3365});
    grafo[2].push_back({1, 3365});

    grafo[1].push_back({11, 1623});
    grafo[11].push_back({1, 1623});

    grafo[1].push_back({17, 1625});
    grafo[17].push_back({1, 1625});

    grafo[2].push_back({3, 907});
    grafo[3].push_back({2, 907});

    grafo[3].push_back({4, 98});
    grafo[4].push_back({3, 98});

    grafo[4].push_back({5, 98});
    grafo[5].push_back({4, 98});

    grafo[5].push_back({6, 79});
    grafo[6].push_back({5, 79});

    grafo[6].push_back({7, 102});
    grafo[7].push_back({6, 102});

    grafo[7].push_back({8, 1886});
    grafo[8].push_back({7, 1886});

    grafo[8].push_back({9, 5828});
    grafo[9].push_back({8, 5828});

    grafo[9].push_back({10, 3828});
    grafo[10].push_back({9, 3828});

    grafo[11].push_back({12, 42});
    grafo[12].push_back({11, 42});

    grafo[12].push_back({13, 82});
    grafo[13].push_back({12, 82});

    grafo[13].push_back({14, 148});
    grafo[14].push_back({13, 148});

    grafo[14].push_back({15, 1496});
    grafo[15].push_back({14, 1496});

    grafo[15].push_back({16, 568});
    grafo[16].push_back({15, 568});

    grafo[16].push_back({10, 4669});
    grafo[10].push_back({16, 4669});

    grafo[17].push_back({18, 206});
    grafo[18].push_back({17, 206});

    grafo[18].push_back({19, 44});
    grafo[19].push_back({18, 44});

    grafo[19].push_back({20, 144});
    grafo[20].push_back({19, 144});

    grafo[20].push_back({21, 220});
    grafo[21].push_back({20, 220});

    grafo[21].push_back({22, 670});
    grafo[22].push_back({21, 670});

    grafo[22].push_back({9, 1336});
    grafo[9].push_back({22, 1336});

    int origen = 16;
    int destino = 10;

    auto resultado = dijkstra(n, origen, destino, grafo);
    int distancia_total = resultado.first;
    std::vector<int> camino = resultado.second;

    if (distancia_total == INF) {
        std::cout << "No hay un camino desde el nodo " << origen << " al nodo " << destino << ".\n";
    } else {
        std::cout << "Camino mas corto desde el nodo " << origen << " al nodo " << destino << ":\n";
        for (int i = 0; i < camino.size(); ++i) {
            std::cout << camino[i];
            if (i < camino.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nDistancia total: " << distancia_total << "\n";
    }

    return 0;
}
