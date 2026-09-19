class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n+1,0);
        vector<int> sell(n+1,0);

        buy[0] = -prices[0];
        sell[0] = 0;
        for(int i = 1;i<n;i++){
            int prev = (i-2 >= 0 )?sell[i-2]:0;
            buy[i] = max(buy[i-1],prev-prices[i]);
            sell[i] = max(sell[i-1],buy[i-1]+prices[i]);
        }
        return sell[n-1];
    }
};
