class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int minP = prices[0];
        int ans = 0;
        for(int i = 1;i<n;i++)
        {
            ans = Math.max(ans,prices[i]-minP);
            minP = Math.min(minP,prices[i]);
        }
        return ans;
    }
}
