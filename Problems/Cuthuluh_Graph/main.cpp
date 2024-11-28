#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// Función para verificar si el grafo es conexo
// Complejidad: O(n + m), ya que utiliza BFS para recorrer todos los nodos y aristas.
bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int count = 0;

    q.push(1); // Inicia el recorrido desde el nodo 1
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Recorre todos los vecinos del nodo actual
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Verifica si todos los nodos fueron visitados
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false; // No es conexo
        }
    }

    return true;
}

// Función para verificar si el grafo tiene exactamente un ciclo simple
// Complejidad: O(n + m), utiliza DFS para identificar ciclos y contar nodos/aristas.
bool hasSingleCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    int edgesCount = 0; // Contador de aristas en el ciclo
    int nodesCount = 0; // Contador de nodos visitados

    // DFS para recorrer el grafo y detectar ciclos
    function<void(int, int)> dfs = [&](int node, int parent) {
        visited[node] = true;
        nodesCount++;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, node);
            } else if (neighbor != parent) {
                edgesCount++; // Encontramos un ciclo
            }
        }
    };

    dfs(1, -1);
    edgesCount /= 2; // Cada arista se cuenta dos veces en un grafo no dirigido

    // El grafo debe ser conexo y contener exactamente un ciclo simple
    return (nodesCount == n && edgesCount == 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    // Si no se cumple n = m, el grafo no puede tener un ciclo simple
    if (m != n) {
        cout << "NO" << endl;
        return 0;
    }

    // Crear la lista de adyacencia
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Verificar condiciones: conexidad y presencia de un único ciclo simple
    if (isConnected(n, adj) && hasSingleCycle(n, adj)) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
