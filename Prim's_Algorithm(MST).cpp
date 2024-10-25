#include <bits/stdc++.h>
using namespace std;

vector<int> primMST(int V, vector<vector<int>>& graph) {
  
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    vector<int> parent(V);

    dist[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = -1, mini = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!vis[v] and dist[v] < mini) {
                mini = dist[v];
                u = v;
            }
        }

        vis[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !vis[v] and graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    return parent;
}

// Driver's code
int main() {
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};

    int V = 5;
    vector<int> parent = primMST(V, graph);

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]]
             << " \n";
    }

    return 0;
}

/*

Output:

Edge 	Weight
0 - 1 	2 
1 - 2 	3 
0 - 3 	6 
1 - 4 	5 


How to implement Prim’s Algorithm?
Follow the given steps to utilize the Prim’s Algorithm mentioned above for finding MST of a graph:

*******************************************************************************************************

1) Create a set mstSet that keeps track of vertices already included in MST. 

2) Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE.
  Assign the key value as 0 for the first vertex so that it is picked first. 

3)While mstSet doesn’t include all vertices 

    * Pick a vertex u that is not there in mstSet and has a minimum key value. 
    
    * Include u in the mstSet. 
    
    * Update the key value of all adjacent vertices of u. To update the key values,
      iterate through all adjacent vertices. 
    
        * For every adjacent vertex v, if the weight of edge u-v is less than the previous
          key value of v, update the key value as the weight of u-v.

*******************************************************************************************************

The idea of using key values is to pick the minimum weight edge from the cut. 
The key values are used only for vertices that are not yet included in MST, 
the key value for these vertices indicates the minimum weight edges connecting them
to the set of vertices included in MST.

*/
