#include <iostream>
#include <vector>
#include <queue>
#include <functional>


using namespace std;

bool isConnected(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    int count = 0;

    // Empezamos desde el nodo 1
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // Revisar si todos los nodos han sido visitados
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

bool hasSingleCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n + 1, false);
    int edgesCount = 0; // Contar las aristas visitadas
    int nodesCount = 0; // Contar los nodos visitados

    function<void(int, int)> dfs = [&](int node, int parent) {
        visited[node] = true;
        nodesCount++;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, node);
            } else if (neighbor != parent) {
                edgesCount++; // Contar ciclos (evitando contar dos veces la misma arista)
            }
        }
    };

    dfs(1, -1);
    edgesCount /= 2; // Cada arista se cuenta dos veces en un grafo no dirigido

    // El grafo debe tener exactamente un ciclo y todos los nodos deben ser parte del mismo componente
    return (nodesCount == n && edgesCount == 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    if (m != n) {
        cout << "NO" << endl;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (isConnected(n, adj) && hasSingleCycle(n, adj)) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
