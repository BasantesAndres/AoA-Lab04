#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> graph(n);

    // Grafo no dirigido de ejemplo
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 5};
    graph[3] = {1};
    graph[4] = {1, 5};
    graph[5] = {2, 4};

    vector<bool> visited(n, false);

    cout << "DFS traversal starting from node 0: ";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}