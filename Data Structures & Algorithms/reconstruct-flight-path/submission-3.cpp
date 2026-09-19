class Solution {
public:
    void dfs(string node,unordered_map<string,priority_queue<string,vector<string>,greater<>>> &adj,
    vector<string> &ans){
        auto &nbr = adj[node];
        while(!nbr.empty()){
            string fr = nbr.top();
            nbr.pop();
            dfs(fr,adj,ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<>>> adj;
        for(auto &ticket:tickets){
            adj[ticket[0]].push(ticket[1]);
        }

        vector<string> ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
