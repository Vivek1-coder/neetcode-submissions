class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node] = 1;
        for(int nbr:adj[node]){
            if(!vis[nbr]){
                dfs(nbr,adj,vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        vector<vector<int>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        dfs(0,adj,visited);
        for(int i = 0;i<n;i++){
            if(visited[i] == 0) return false;
        }
        return true;
    }
};
