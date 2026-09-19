class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        for(int i = 0;i<n;i++){
            vector<int> freq(26,0);
            for(char ch:strs[i]){
                freq[ch-'a']++;
            }
            string temp = "";
            for(int i = 0;i<26;i++){
                int f = freq[i];
                while(f--){
                    temp += ('a'+i);
                }
            }
            // cout<<temp<<endl;
            mp[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
