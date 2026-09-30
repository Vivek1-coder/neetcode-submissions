class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = 0;
        int maxSum = nums[0];
        for(int i = 0;i<nums.length;i++){
            currSum += nums[i];
            if(currSum < nums[i]){
                currSum = nums[i];
            }
            maxSum = Math.max(maxSum,currSum);
        }
        return maxSum;
    }
}
