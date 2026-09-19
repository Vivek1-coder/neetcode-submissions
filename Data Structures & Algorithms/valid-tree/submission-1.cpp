class Solution {
public:
    bool dfs(int node,int par,vector<vector<int>> &adj,vector<int> &vis){
        vis[node] = true;
        for(int nbr:adj[node]){
            if(!vis[nbr]){
                bool temp = dfs(nbr,node,adj,vis);
                if(!temp) return false;
            }
            else if(nbr != par) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool temp = dfs(0,-1,adj,vis);
        if(!temp) return false;
        for(int i = 0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
