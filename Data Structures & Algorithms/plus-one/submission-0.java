class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int carry = 1;
        for(int i = n-1;i>=0;i--){
            int num = digits[i]+carry;
            digits[i] = num%10;
            carry = num/10;
        }

        if(carry == 0){
            return digits;
        }
        int[] ans = new int[n+1];
        ans[0] = carry;
        for(int i = 1;i<=n;i++){
            ans[i] = digits[i-1];
        }
        return ans;
    }
}
