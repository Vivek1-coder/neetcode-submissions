class Solution {
public:
    bool isCycle(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &dfsCall){
        vis[node] = 1;
        dfsCall[node] = 1;
        for(int nbr:adj[node]){
            if(!vis[nbr]){
                if(isCycle(nbr,adj,vis,dfsCall)) return true;
            }
            else{
                if(dfsCall[nbr] == 1) return true;
            }
        }
        dfsCall[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> vis(numCourses,0);
        vector<int> dfsCall(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            if(!vis[i] && isCycle(i,adj,vis,dfsCall)){
                return false;
            }
        }
        return true;
    }
};
