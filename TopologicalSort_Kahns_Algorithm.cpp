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


    Kahn’s Algorithm for Topological Sorting is a method used to order the vertices of
    a directed graph in a linear order such that for every directed edge from vertex
    A to vertex B, A comes before B in the order. The algorithm works by repeatedly finding
    vertices with no incoming edges, removing them from the graph, and updating the incoming
    edges of the remaining vertices. This process continues until all vertices have been ordered.
    
    
    Topological sorting only exists in Directed Acyclic Graph (DAG). If the nodes of a graph are 
    connected through directed edges and the graph does not contain a cycle, it is called a directed
    acyclic graph(DAG). 
    
    The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices
    such that if there is an edge between node u and v(u -> v), node u appears before v in that ordering.
    
    Now, let's understand Why topological sort only exists in DAG:
    
    Case 1 : (If the edges are undirected): If there is an undirected edge between node u and v, it signifies
    that there is an edge from node u to v(u -> v) as well as there is an edge from node v to u(v -> u). 
    But according to the definition of topological sorting, it is practically impossible to write such ordering
    where u appears before v and v appears before u simultaneously. So, it is only possible for directed edges.
    
    Case 2 : (If the directed graph contains a cycle): The following directed graph contains a cycle:
    
    
    If we try to get topological sorting of this cyclic graph, for edge 1->2, node 1 must appear before 2, 
    for edge 2->3, node 2 must appear before 3, and for edge 3->1, node 3 must appear before 1 in the linear
    ordering. But such ordering is not possible as there exists a cyclic dependency in the graph. Thereby, 
    topological sorting is only possible for a directed acyclic graph.
*/
          
