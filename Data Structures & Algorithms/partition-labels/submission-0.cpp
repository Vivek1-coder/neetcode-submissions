class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> mp(26,vector<int> (2,-1));
        int n = s.size();
        for(int i = 0;i<n;i++){
            int idx = s[i]-'a';
            if(mp[idx][0] == -1){
                mp[idx][0] = i;
            }
            mp[idx][1] = i;
        }
        sort(mp.begin(),mp.end());
        vector<vector<int>> ans;
        int i = 0;
        while(mp[i][0] == -1) i++;
        ans.push_back({mp[i][0],mp[i][1]});
        i++;
        while(i<26){
            if(ans.back()[1] > mp[i][0]){
                ans.back()[1] = max(ans.back()[1],mp[i][1]);
            }
            else{
                ans.push_back({mp[i][0],mp[i][1]});
            }
            i++;
        }
        vector<int> res;
        for(int i = 0;i<ans.size();i++){
            res.push_back({ans[i][1]-ans[i][0]+1});
        }
        return res;
    }
};
