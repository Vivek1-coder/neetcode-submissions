class Solution {
public:
    bool isAnargams(string &s1,string &s2){
        if(s1.size() != s2.size()) return false;

        int n = s1.size();
        vector<int> mp(26,0);
        for(int i = 0;i<n;i++){
            mp[s1[i]-'a']++;
            mp[s2[i]-'a']--;
        }
        for(int freq:mp){
            if(freq != 0) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        vector<bool> visited(n+1,0);
        for(int i = 0;i<n;i++){
            if(visited[i]) continue;
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = i+1;j<n;j++){
                if(isAnargams(strs[i],strs[j])){
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            visited[i] = true;
            ans.push_back(temp);
        }
        return ans;
    }
};
