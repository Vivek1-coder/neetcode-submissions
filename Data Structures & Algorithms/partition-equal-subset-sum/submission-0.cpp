class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2 != 0) return false;
        int target = total/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (target + 1,0));
        dp[0][0] = 1;
        for(int i = 1;i<=n;i++){
            for(int t = 0;t<=target;t++){
                dp[i][t] = (dp[i-1][t]);
                if(t>=nums[i-1])
                    dp[i][t] |= (dp[i-1][t-nums[i-1]]);
            }
        }
        return dp[n][target];
    }
};
