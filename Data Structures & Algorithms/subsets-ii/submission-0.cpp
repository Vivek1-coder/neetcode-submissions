class Solution {
public:
    void solve(vector<int> &nums,int idx,vector<vector<int>> &ans,vector<int> &temp){

        for(int i = idx;i<nums.size();i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            // solve(nums,idx+1,ans,temp);
            temp.push_back(nums[i]);
            solve(nums,i+1,ans,temp);
            temp.pop_back();
        }
         ans.push_back(temp);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,0,ans,temp);
        return ans;
    }
};
