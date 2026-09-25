class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> temp(strs.begin(),strs.end());
        for(int i = 0;i<n;i++){
            sort(temp[i].begin(),temp[i].end());
        }
        unordered_map<string,vector<int>> mp;
        for(int i = 0;i<n;i++){
            mp[temp[i]].push_back(i);
        }

        vector<vector<string>> ans;
        for(auto &it:mp){
            vector<string> curr;
            for(int idx:it.second){
                curr.push_back(strs[idx]);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
