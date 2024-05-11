#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<vector<int>> adj;
    vector<bool> vis;

    Graph(int v)
    {
        this->v = v;
        this->adj = vector<vector<int>>(v);
        this->vis = vector<bool>(v);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int s)
    {
        vis[s] = true;

        cout << s << " ";

        for (int i : adj[s])
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
    }

    void bfs(int s)
    {
        queue<int> q;
        q.push(s);

        vis[s] = true;

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            cout << cur << " ";

            for (int i : adj[cur])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(7);
    g.add(0, 1);
    g.add(0, 2);
    g.add(1, 3);
    g.add(1, 4);
    g.add(2, 5);
    g.add(2, 6);

    cout << "Bfs Starting from vertex 0 : \n";
    g.bfs(0);
    cout << "\nDfs Starting from vertex 0 : \n";
    g.dfs(0);


    return 0;
}