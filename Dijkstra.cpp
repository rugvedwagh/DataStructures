#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(vector<vector<int>> &graph, int src, int V)
{
    vector<int> dist(V,INT_MAX);
    vector<bool> visited(V,false);
    
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
      
        int min = INT_MAX, u;

        for (int v = 0; v < V; v++){
            if (!visited[v] && dist[v] <= min){
                min = dist[v];
                u = v;
            }
        }
        
        visited[u] = true;

        for (int v = 0; v < V; v++){
            
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}


int main()
{
  
    int V = 6;
    
    vector<vector<int>> graph = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 1, 5},
        {0, 0, 3, 1, 0, 2},
        {0, 0, 0, 5, 2, 0}
    };
          
    int source = 0;
    vector<int> dist = Dijkstra(graph, source, V);
    
    int count = 0;
    for(auto i : dist){
      cout<<"Smallest distance from vertex "<<source<<" to "<<count++<<" = "<<i<<endl;
    }

    return 0;
}


/*
OUTPUT

Smallest distance from vertex 0 to 0 = 0
Smallest distance from vertex 0 to 1 = 2
Smallest distance from vertex 0 to 2 = 3
Smallest distance from vertex 0 to 3 = 7
Smallest distance from vertex 0 to 4 = 6
Smallest distance from vertex 0 to 5 = 8

***** NOTES *****

In Dijkstra's algorithm, the source node doesn't need to be
explicitly marked as visited initially because its shortest 
distance is set to zero, which inherently handles its inclusion
in the shortest path tree (SPT) during the first iteration of 
the algorithm. 

The first 'u' is actually the source node only

In Dijkstra's algorithm, the outer loop runs from 0 to V-1 for the following reasons:

Number of Vertices to Process: The algorithm is designed to process each vertex
exactly once, except the starting vertex which is considered already processed

. Since the graph has V vertices, and the starting vertex is processed separately
by initializing its distance to zero, the algorithm needs to iterate V-1 times to 
process the remaining V-1 vertices.

*/
