# Graphs

Incluir queue para poder usar priority_queue y usar nodo con menor distancia

Incluir limits para usar INF si no se puede acceder a un nodo.

Definir una estructura nodo que almacene distancia y numero de nodo
Sobre cargar el operador > para poder comparar distancias

Definir la funcion Dijkstra que devuelve un par, la distancia total y el vector del camino seguido. Recibe el tamaño total del grafo, nodo origen, nodo destino y el grafo.

Inicializar el vector distancias en infinito menos en el origen, cuyo valor es 0.
Inicializar el vector predecesor con -1 en todas las posiciones.

Definir una priority queue que guarde elementos de estructura Nodo, use un vector para almacenar todo y con greater dale mayor prioridad a los elementos con un valor numerico menor.

Mientras esta queue no este vacia, toma el valor de la distancia y numero de nodo del valor con mayor prioridad en la queue.
Se elimina ese elemento de la queue.

Si el nodo actual es igual al destino se rompe el ciclo.

Si la distancia actual del nodo actual es mayor a la registrada en el vector de distancias, esto quiere decir que ya se habia evaluado el nodo y se pasa a la siguiente ejecucion.

Actualiza los valores de distancia en los vecinos del nodo actual y los agrega a la queue para tomar el nodo con menor distancia en la siguiente ejecucion del while.

Se agrega el nodo actual en la posicion del nodo vecino para poder llevar un registro del camino utilizado
Mientras el elemento del vector predecesor sea != -1, se agrega al vector camino. 
Finalmente se regresa el vector camino invertido y tenemos el path

La funcion dijkstra regresa <distancias[destino], camino>
