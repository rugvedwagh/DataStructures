/*
  function Dijkstra(Graph, source):
    initialize distance[source] = 0 and distance[other vertices] = infinity
    initialize visited[all vertices] = false
    
    while there are unvisited vertices:
        current = vertex with the smallest distance among unvisited vertices
        
        for each neighbor of current:
            if neighbor is unvisited:
                calculate tentative distance to neighbor
                if tentative distance is less than distance[neighbor]:
                    update distance[neighbor]
        
        mark current as visited
    
    return distance[]  // Shortest distances from source to all vertices
*/


#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // A large integer to represent infinity

void dijkstra(vector<vector<int>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[source] = 0;

    while (true) {
        int u = -1;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1 || dist[u] == INF) {
            break; // All remaining vertices are unreachable.
        }

        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF) {
            cout << "Vertex " << i << ": Infinity" << endl;
        } else {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
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
