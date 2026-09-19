class Solution {
public:
    void solve(vector<int> &nums,int idx,vector<int> &temp,vector<vector<int>> &ans){
        if(idx >= nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int i = 0;i<nums.size();i++){
            if(temp[i] == -11){
                temp[i] = nums[idx];
                solve(nums,idx+1,temp,ans);
                temp[i] = -11;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp(n,-11);
        solve(nums,0,temp,ans);
        return ans;
    }
};
