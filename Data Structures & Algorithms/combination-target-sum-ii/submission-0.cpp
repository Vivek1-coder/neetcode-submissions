class Solution {
public:
    void solve(vector<int> &nums,int idx,int target,vector<int> &temp,
    vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx == nums.size()) return;
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            if(target < nums[i]) break;
            temp.push_back(nums[i]);
            solve(nums,i+1,target-nums[i],temp,ans);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,temp,ans);
        return ans;
    }
};
