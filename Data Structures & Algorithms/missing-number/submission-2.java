class Solution {
    public int missingNumber(int[] nums) {
       int ans = 0;
       int st = 0;
       for(int num:nums){
        ans ^= num;
        ans ^= st;
        st++;
       } 
       ans ^= st;
       return ans;
    }
}
