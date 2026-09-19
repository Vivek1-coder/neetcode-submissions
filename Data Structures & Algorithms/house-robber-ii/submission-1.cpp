class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n+1,-1e8);
        vector<int> dp2(n+1,-1e8);
        dp1[0] = 0;
        dp1[1] = nums[0];
        for(int i = 1;i<n-1;i++){
            dp1[i+1] = max(dp1[i],dp1[i-1]+nums[i]);
        }
        dp2[0] = 0;
        dp2[1] = 0;
        for(int i = 1;i<n;i++){
            dp2[i+1] = max(dp2[i],dp2[i-1]+nums[i]);
        }
        int ans1 = max(dp1[n],dp1[n-1]);
        int ans2 = max(dp2[n],dp2[n-1]);
        return max(ans1,ans2);
    }
};
