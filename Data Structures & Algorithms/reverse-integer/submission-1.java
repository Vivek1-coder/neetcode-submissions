class Solution {
    public int reverse(int x) {
        boolean neg = false;
        if(x < 0) neg = true;

        long temp = Math.abs(x);
        System.out.println(temp);
        System.out.println(Integer.MAX_VALUE);
        long ans = 0;
        long t = 10;
        while(temp > 0){
            long dig = temp%t;
            temp /= t;
            ans = ((ans*10)+dig);
        }
        if(neg){
            ans *= -1;
        }
        System.out.println(ans);
        if(ans > (long)Integer.MAX_VALUE){
            return 0;
        }
        if(ans < Integer.MIN_VALUE){
            return 0;
        }
        return (int)ans;
    }
}
