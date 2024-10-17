class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int find(int i){
        if(i==par[i]){
            return i;
        }
        return par[i] = find(par[i]);
    }

    void Union(int x, int y){
        int xpar = find(x); 
        int ypar = find(y); 

        if(xpar==ypar){
            return;
        }
        if(rank[xpar]>rank[ypar]){
            par[ypar] = xpar;
        }
        else if(rank[xpar]<rank[ypar]){
            par[xpar] = ypar;
        }
        else{
            rank[xpar]++;
            par[ypar] = xpar;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        par.resize(edges.size()+1);
        rank.resize(edges.size()+1, 0);

        for(int i=1; i<=edges.size(); i++){
            par[i] = i;
        }

        for(auto edge : edges){
            int xpar = find(edge[0]);
            int ypar = find(edge[1]);

            if(xpar==ypar){
                return edge;
            }
            else{
                Union(edge[0], edge[1]);
            }
        }

        return {};
    }
};
