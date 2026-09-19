class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        unordered_set<string> mp(wordDict.begin(),wordDict.end());
        for(int i = 1;i<=n;i++){
            string t = "";
            for(int j = i;j<=n;j++){
                t += s[j-1];
                if(mp.count(t)){
                    dp[j] = dp[j]|dp[i-1];
                }
            }
        }
        
        return dp[n];
    }
};
