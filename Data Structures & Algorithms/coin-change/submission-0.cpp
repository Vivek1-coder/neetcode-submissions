class Solution {
public:
    int solve(vector<int> &coins,int amount,int idx){
        if(amount == 0) return 0;
        if(amount < 0 || idx == coins.size()) return 1e8;
        int inc = solve(coins,amount-coins[idx],idx)+1;
        int des = solve(coins,amount,idx+1);
        return min(inc,des);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount,0);
        return ans >= 1e8 ? -1 : ans;
    }
};
