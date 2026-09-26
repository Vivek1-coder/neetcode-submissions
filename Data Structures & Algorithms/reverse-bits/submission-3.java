class Solution {
    public int reverseBits(int n) {
        int ans = 0;
        int mask = (1<<31);
        for(int i = 0;i<32;i++){
            if(((n)&(1<<i)) != 0){
                ans = (ans|mask);
            }
            mask = (mask>>>1);
        }
        return ans;
    }
}
