class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int idx){
        if(parent[idx] == idx) return idx;
        return parent[idx] = findParent(parent[idx]);
    }

    void unite(int u,int v){
        u = findParent(u);
        v = findParent(v);
        if(u != v){
            if(rank[u] < rank[v]){
                parent[u] = v;
            }
            else if(rank[v] < rank[u]){
                parent[v] = u;
            }
            else{
                parent[v] = u;
                rank[u]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i = 1;i<=n;i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            if(findParent(u) == findParent(v)){
                return {u,v};
            }
            unite(u,v);
        }
        return {-1,-1};
    }
};
