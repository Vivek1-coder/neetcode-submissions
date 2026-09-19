class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        if(s[n-1] != '0') dp[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            int curr = s[i]-'0';
            if(curr != 0) dp[i] += dp[i+1];
            if((curr == 1) || (curr == 2 && s[i+1] >= '0' && s[i+1] <= '6')){
                dp[i] += dp[i+2];
            }
        }
        for(int i = 0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        return dp[0];
    }
};
