class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1,0);
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                dp[j] = max(dp[j],dp[j-1]);
                if(prices[j] > prices[i]){
                    int prev = (i-2 >= 0)?dp[i-2]:0;
                    dp[j] = max(dp[j],prices[j]-prices[i]+prev);
                }
            }
        }
        return dp[n-1];
    }
};
