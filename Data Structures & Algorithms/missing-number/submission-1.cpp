class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int st = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans ^= (st^nums[i]);
            st++;
        }
        ans ^= st;
        return ans;
    }
};
