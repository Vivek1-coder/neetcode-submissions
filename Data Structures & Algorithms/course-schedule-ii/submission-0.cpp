class Solution {
public:
    bool dfs(int idx,vector<vector<int>> &adj,vector<int> &vis,vector<int> &dfsCall,
        vector<int> &st){
            vis[idx] = 1;
            dfsCall[idx] = 1;
            for(int nbr:adj[idx]){
                if(!vis[nbr]){
                    bool cycle = dfs(nbr,adj,vis,dfsCall,st);
                    if(cycle) return true;
                }
                else{
                    if(dfsCall[nbr]) return true;
                }
            }
            dfsCall[idx] = 0;
            st.push_back(idx);
            return false;
        }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }
        int n = numCourses;
        vector<int> st;
        vector<int> vis(n,0);
        vector<int> dfsCall(n,0);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                bool cycle = dfs(i,adj,vis,dfsCall,st);
                if(cycle) return {};
            }
        }
        reverse(st.begin(),st.end());
        return st;
    }
};
