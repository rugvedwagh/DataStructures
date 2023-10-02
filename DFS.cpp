#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int v;
    vector<vector<int>> adj;
    vector<bool> vis;

public:
    graph(int v)
    {
        this->v = v;
        this->adj = vector<vector<int>>(v);
        this->vis = vector<bool>(v, false);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
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
};

int main(){
    graph g(7);
    g.add(0,1);
    g.add(0,2);
    g.add(1,3);
    g.add(1,4);
    g.add(2,5);
    g.add(2,6);

    cout<<"Starting from vertex 0 : \n";
    g.dfs(0);

    return 0;
}
