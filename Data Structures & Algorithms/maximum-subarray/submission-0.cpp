class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sm = 0;
        for(int num:nums){
            sm += num;
            if(sm < num){
                sm = num;
            }
            maxSum = max(maxSum,sm);
        }
        return maxSum;
    }
};
