class Solution {
public:
    int solve(vector<int> &coins,int amount,int idx){
        if(amount == 0) return 0;
        if(amount < 0 || idx == coins.size()) return 1e8;

        int t = amount/coins[idx];
        int ans = INT_MAX;
        while(t){
            int inc = solve(coins,amount-(t*coins[idx]),idx+1) + t;
            ans = min(ans,inc);
            t--;
        }
        int des = solve(coins,amount,idx+1);
        return min(des,ans);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount,0);
        return ans >= 1e8 ? -1 : ans;
    }
};
