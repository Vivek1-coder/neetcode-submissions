class Solution {
    // void print(int ans){
    //     System.out.println(" ");
    //     for(int i = 31;i>=0;i--){
    //         if(((ans)&(1<<i)) != 0){
    //             System.out.print(1);
    //         }else{
    //             System.out.print(0);
    //         }
    //     }
    // }
    public int reverseBits(int n) {
        int ans = 0;
        int mask = (1<<31);
        for(int i = 0;i<32;i++){
            if(((n)&(1<<i)) != 0){
                ans = (ans|mask);
            }
            // print(mask);
            mask = (mask>>>1);
        }
        return ans;
    }
}
