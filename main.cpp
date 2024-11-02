#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

struct Nodo {
    int distancia, nodo;
    bool operator>(const Nodo &otro) const { //overflow de operador para poder comparar distancias en el algoritmo
        return distancia > otro.distancia;
    }
};

std::pair<int, std::vector<int>> dijkstra(int n, int origen, int destino, const std::vector<std::vector<std::pair<int, int>>> &grafo) {
    std::vector<int> distancias(n, INF); //llenar vector distancias de INF
    std::vector<int> predecesor(n, -1);  // almacenar el nodo anterior en el camino
    distancias[origen] = 0; //igualar la distancia en el origen a 0

    std::priority_queue<Nodo, std::vector<Nodo>, std::greater<Nodo>> pq; //crear priority queue que almacene Nodo, y que a su vez almacene los Nodos en un vector y le de prioridad a los que tienen menor valor numerico

    pq.push({0, origen});

    while (!pq.empty()) { //mientras la lista no este vacia
        int distancia_actual = pq.top().distancia; //tomar la menor distancia registrada
        int nodo_actual = pq.top().nodo; //tomar que nodo estamos
        pq.pop(); //eliminarlo para poder seguir evaluando en siguientes ejecucuiones

        if (nodo_actual == destino) break; //llegamos al destino

        if (distancia_actual > distancias[nodo_actual]) continue; //si la distancia registrada del nodo acual es menor quiere decir que ya lo habiamos evaluado, por eso se brinca a la siguiente ejecucion

        for (const auto &vecino : grafo[nodo_actual]) { //evaluar a los vecinos
            int nodo_vecino = vecino.first;
            int peso_arista = vecino.second;

            if (distancias[nodo_actual] + peso_arista < distancias[nodo_vecino]) { //si la distancia es menor a la registrada lo guardamos
                distancias[nodo_vecino] = distancias[nodo_actual] + peso_arista; //actualizar el valor de distancia del nodo vecino
                predecesor[nodo_vecino] = nodo_actual; //registrar el nodo actual en la posicion del nodo vecino para poder registrarlo efectivamente
                pq.push({distancias[nodo_vecino], nodo_vecino}); //guardar todas las distancias de los vecinos en la priority queue
            }
        }
    }

    std::vector<int> camino;
    for (int v = destino; v != -1; v = predecesor[v]) {
        camino.push_back(v); //eliminar los valores vacios en predecesor y eliminar el -1
    }
    std::reverse(camino.begin(), camino.end()); //voltear el array para ver el camino en orden

    return {distancias[destino], camino};
}

int main() {
    int n = 23; //definir el tamaño del grafo
    std::vector<std::vector<std::pair<int, int>>> grafo(n); //crear el grafo

    //agregar los nodos al grafo
    grafo[0].push_back({1, 326});
    grafo[1].push_back({2, 3365});
    grafo[1].push_back({11, 1623});
    grafo[1].push_back({17, 1625});
    grafo[2].push_back({3, 907});
    grafo[3].push_back({4, 98});
    grafo[4].push_back({5, 98});
    grafo[5].push_back({6, 79});
    grafo[6].push_back({7, 102});
    grafo[7].push_back({8, 1886});
    grafo[9].push_back({10, 3828});
    grafo[11].push_back({12, 42});
    grafo[12].push_back({13, 82});
    grafo[13].push_back({14, 148});
    grafo[14].push_back({15, 1496});
    grafo[15].push_back({16, 568});
    grafo[16].push_back({10, 4669});
    grafo[17].push_back({18, 206});
    grafo[18].push_back({19, 44});
    grafo[19].push_back({20, 144});
    grafo[20].push_back({21, 220});
    grafo[21].push_back({22, 670});
    grafo[22].push_back({9, 1336});

    int origen = 0;
    int destino = 10;

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
