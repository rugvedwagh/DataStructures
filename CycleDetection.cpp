bool Util(int v, vector<vector<int>>& adj, bool visited[], int parent) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (!visited[i]) {
            if (Util(i, adj, visited, v)){
                return true;
            }  
        }
        else if (i != parent){
            return true;
        }  
    }
    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    bool* visited = new bool[V]{false};

    for (int u = 0; u < V; u++) {
        if (!visited[u]){
            if (Util(u, adj, visited, -1)){
                return true;
            }  
        }
    }
    return false;
}
