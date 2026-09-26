class Solution {
    public int reverse(int x) {
        long org = x;
        org = Math.abs(org);
        long res = Long.parseLong(new StringBuilder(String.valueOf(org)).reverse().toString());
        if(x < 0){
            res *= -1;
        }

        if(res < Integer.MIN_VALUE || res > Integer.MAX_VALUE)
        {
            return 0;
        }
        return (int)res;
    }
}
