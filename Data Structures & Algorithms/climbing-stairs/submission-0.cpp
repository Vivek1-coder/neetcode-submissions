class Solution {
public:
    int climbStairs(int n) {
        int st = 1;
        int sec = 1;
        if(n <= 1){
            return 1;
        }
        for(int i = 2;i<=n;i++){
            int curr = sec+st;
            st = sec;
            sec = curr;
        }
        return sec;
    }
};
