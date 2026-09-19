class Solution {
public:
    int reverse(int x) {
        const int maxi = INT_MAX;
        const int mini = INT_MIN;
        int res = 0;
        while(x != 0){
            int dig = x%10;
            x /= 10;
            cout<<dig<<" ";
            if((res > maxi/10) || ((res == maxi/10) && (dig > maxi%10))) return 0;
            if((res < mini/10) || ((res == mini/10) && (dig < mini%10))) return 0;
            res = res*10 + dig;
        }
        return res;
    }
};
