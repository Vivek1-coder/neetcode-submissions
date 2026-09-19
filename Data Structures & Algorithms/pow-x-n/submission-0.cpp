class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0){
            x = 1/x;
            n = abs(n);
        }
        double res = 1;
        while(n > 0){
            if(n%2 != 0){
                res *= x;
            }
            x *= x;
            n /= 2;
        }
        return res;
    }
};
