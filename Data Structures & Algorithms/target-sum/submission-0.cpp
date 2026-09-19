class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        int n = nums.size();
        for(int num:nums){
            total += (abs(num));
        }
        vector<int> prev(2*total+2,0);
        int mid = total;
        prev[mid] = 1;
        for(int i = 0;i<n;i++){
            vector<int> curr(2*total + 2,0);
            for(int sm = 0;sm<2*total+2;sm++){
                if(sm >= nums[i]){
                    curr[sm] = prev[sm-nums[i]];
                }
                if(sm+nums[i] <= 2*total){
                    curr[sm] += prev[sm+nums[i]];
                }
            }
            prev = curr;
        }
        return prev[mid+target];
    }
};
