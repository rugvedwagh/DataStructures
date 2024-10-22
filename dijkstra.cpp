#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &graph, int src, int V)
{
    vector<int> dist(V, INT_MAX); // The output array.  dist[i] will hold the
    vector<bool> vis(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int min = INT_MAX, u;

        for (int v = 0; v < V; v++)
        {
            if (!vis[v] and dist[v] <= min)
            {
                min = dist[v];
                u = v;
            }
        }

        vis[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!vis[v] and graph[u][v] and dist[u] != INT_MAX and dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

// driver's code
int main()
{

    int V = 6;

    vector<vector<int>> graph = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 1, 5},
        {0, 0, 3, 1, 0, 2},
        {0, 0, 0, 5, 2, 0}};

    // Function call
    vector<int> ans = dijkstra(graph, 0, V);

    int count = 0;

    for (auto i : ans)
    {
        cout << "Smallest distance from vertex 0 to " << count++ << " = " << i << endl;
    }

    return 0;
}

/*
Smallest distance from vertex 0 to 0 = 0
Smallest distance from vertex 0 to 1 = 2
Smallest distance from vertex 0 to 2 = 3
Smallest distance from vertex 0 to 3 = 7
Smallest distance from vertex 0 to 4 = 6
Smallest distance from vertex 0 to 5 = 8*/
