class Solution {
public:
    void solve(vector<int> &nums,int target,int idx,vector<int> &temp,
        vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx;i<nums.size();i++){
            if(target < nums[i]) break;
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],i,temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,target,0,temp,ans);
        return ans;
    }
};
