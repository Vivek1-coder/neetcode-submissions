class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] suff = new int[n];
        suff[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1]*nums[i+1];
        }
        int pre = 1;
        int[] ans = new int[n];
        for(int i = 0;i<n;i++){
            ans[i] = pre*suff[i];
            if(i != n-1) pre *= nums[i]; 
        }
        return ans;
    }
}  
