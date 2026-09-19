class Solution {
public:
    int solve(int num){
        int ans = 0;
        while(num > 0){
            int rem = num%10;
            num /= 10;
            ans += (rem*rem);
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(!st.count(n)){
            st.insert(n);
            int newNum = solve(n);
            if(newNum == 1) return true;
            n = newNum;
        }
        return false;
    }
};
