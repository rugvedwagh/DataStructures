#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    int v;
    vector<vector<int>> adj;

public:
    graph(int v)
    {
        this->v = v;
        this->adj = vector<vector<int>>(v);
    }

    void add(int u, int v)
    {
        adj[u].push_back(v);
    }

    void bfs(int s)
    {
        queue<int> q;
        vector<bool> vis(v, false);

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

int main() {
    graph g(7); // Create a graph with 7 vertices

    g.add(0, 1);
    g.add(0, 2);
    g.add(1, 3);
    g.add(1, 4);
    g.add(2, 5);
    g.add(3, 1);
    g.add(4, 1);
    g.add(5, 2);
    g.add(5, 6);

    cout << "BFS starting from vertex 0: ";
    g.bfs(0);

    return 0;
}

/*

         0
        / \
       1   2
      / \ / \
     3   4   5
              \
               6

*/
