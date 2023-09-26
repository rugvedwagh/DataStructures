#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        this->adj = vector<vector<int>>(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;
        for (const int &neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }

    void topologicalSort()
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        cout << "Topological Sort: ";
        while (!Stack.empty())
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort: ";
    g.topologicalSort();

    return 0;
}
