
#include <iostream>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(vector<vector<int>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[source] = 0;

    int count = 0;
    while (count < V - 1) {
        int u;
        int min = INT_MAX;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && (dist[i]<=min)) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        int v = 0;
        while (v < V) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
            v++;
        }

        count++;
    }

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<vector<int>> graph(V, vector<int>(V, 0));

    // Adding edges to the graph
    graph[0][1] = 2;
    graph[0][2] = 4;
    graph[1][2] = 1;
    graph[1][3] = 7;
    graph[2][4] = 3;
    graph[3][4] = 1;
    graph[3][5] = 5;
    graph[4][5] = 2;

    int source = 0; // Source vertex

    dijkstra(graph, source);

    return 0;
}
