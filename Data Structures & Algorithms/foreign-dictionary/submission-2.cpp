class Solution {
public:
    bool dfs(char node, unordered_map<char,vector<char>> &adj,string &ans,vector<int> &vis,
    vector<int> &dfsCall){
        vis[node-'a'] = 1;
        dfsCall[node-'a'] = 1;
        for(char nbr:adj[node]){
            if(!vis[nbr-'a']){
                if(!dfs(nbr,adj,ans,vis,dfsCall)) return false;
            }
            else{
                if(dfsCall[nbr-'a']) return false;
            }
        }
        dfsCall[node-'a'] = 0;
        ans += node;
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        unordered_map<char,vector<char>> adj;
        if(words.size() == 1) return words[0];
        vector<int> present(26,0);
        string st = words[0];
        for(int i = 1;i<words.size();i++){
            string curr = words[i];
            int idx = 0;
            while(idx<st.size() && idx<curr.size() && st[idx] == curr[idx]){
                idx++;
            }
            if(idx < st.size()){
                if(idx < curr.size()){
                    adj[st[idx]].push_back(curr[idx]);
                }
                else{
                    return "";
                }
            }
            st = curr;
        }

        string ans = "";
        vector<int> vis(26,0);
        vector<int> dfsCall(26,0);
        for(int i = 0;i<26;i++){
            char ch = ('a'+i);
            if(adj.count(ch) && !vis[ch-'a'] && !dfs(ch,adj,ans,vis,dfsCall)) return "";
        }
        reverse(ans.begin(),ans.end());
        
        for(int i = 0;i<words.size();i++){
            for(char ch:words[i]){
                if(!vis[ch-'a']){
                    ans += ch;
                    vis[ch-'a'] = 1;
                }
            }
        }
        return ans;
    }
};
