#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj_list[])
    {
        // Initialize indegree array to count incoming edges for each vertex
        vector<int> indegree(V, 0);

        // Calculate indegrees for each vertex
        for (int i = 0; i < V; i++)
        {
            for (int j : adj_list[i])
            {
                indegree[j]++;
            }
        }

        // Initialize a queue for BFS
        queue<int> q;

        // Add vertices with 0 indegree to the queue
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Initialize the result vector for the topological order
        vector<int> result;

        // Perform BFS
        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            // Add the vertex to the result
            result.push_back(u);

            // Decrease the indegree of adjacent vertices and enqueue them if indegree becomes 0
            for (int v : adj_list[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

int main()
{

    int N = 6; // Number of vertices

    vector<int> adj[N];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> res = obj.topoSort(N, adj);

    for (int vertex : res)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}


/*

        5
       / \
      /   \
     /     \
    0 --- 2
     \   /
      \ /
       4
        \
         \
          1
          ^
          |
          3
*/
          
