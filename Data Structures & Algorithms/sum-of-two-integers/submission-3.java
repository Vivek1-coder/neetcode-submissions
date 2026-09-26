class Solution {
    public int getSum(int a, int b) {
        // int carry = 0;
        int ans = 0;
        do{
            ans = (a^b);
            int carry = (a&b);
            carry = (carry<<1);
            a = ans;
            b = carry;
        }while(b != 0);
        return ans;
    }
}
