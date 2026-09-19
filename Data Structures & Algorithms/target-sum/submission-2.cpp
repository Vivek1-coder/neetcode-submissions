class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<int> prev(total+1,0);
        prev[0] = 1;
        for(int i = 0;i<n;i++){
            vector<int> curr(total+1,0);
            for(int sm = 0;sm<=total;sm++){
                curr[sm] = prev[sm];
                if(sm >= nums[i]){
                    curr[sm] += prev[sm-nums[i]];
                }
            }
            prev = curr;
        }
        int ans = 0;
        // for(int i = 0;i<=total;i++){
        //     cout<<prev[i]<<" ";
        // }
        // cout<<endl;
        for(int sm = 0;sm<=total;sm++){
            int rest = total-sm;
            if(sm-rest == target){
                ans += prev[sm];
            }
        }
        return ans;
    }
};
