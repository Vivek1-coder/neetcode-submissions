class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e8);
        dp[0] = 0;
        sort(coins.begin(),coins.end());
        for(int i = 1;i<=amount;i++){
            int mini = 1e8;
            for(int &coin:coins){
                if(coin > i) break;
                mini = min(mini,1+dp[i-coin]);
            }
            dp[i] = mini;
        }
        return dp[amount]>=1e8?-1:dp[amount];
    }
};
