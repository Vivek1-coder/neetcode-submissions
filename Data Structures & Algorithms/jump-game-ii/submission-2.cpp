class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        int jmp = 0;
        int i = 0;
        while(maxPos < n-1){
            int temp = maxPos;
            for(;i<=maxPos && i<n;i++){
                temp = max(temp,i+nums[i]);
            }
            maxPos = temp;
            jmp++;
            if(maxPos >= n-1){
                return jmp;
            }
        }
        return jmp;
    }
};
