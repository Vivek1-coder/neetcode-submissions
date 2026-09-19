class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> mp(nums.begin(),nums.end());
        for(int num:mp){
            if(mp.count((num)-1)) continue;
            int nm = num;
            int currLen = 0;
            while(mp.count(nm)){
                currLen++;
                nm++;
            }
            ans = max(ans,currLen);
        }
        return ans;
    }
};
