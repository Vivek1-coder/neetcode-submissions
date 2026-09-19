class Solution {
public:
    // int solve(vector<int> &nums,int i,int j){
    //     if(j > i) return 0;

    //     for(int k = i+1;k<j;k++){
    //         int left = solve(nums,i,k);
    //         int right = solve(nums,k,j);
    //         int curr = left+right+
    //     }
    // }
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(int num:nums){
            arr.push_back(num);
        }
        arr.push_back(1);
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i = 0;i<n;i++){
            dp[i][i] = arr[i];
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i+2;j<n;j++){
                for(int k = i+1;k<j;k++){
                    int curr = dp[i][k] + arr[i]*arr[j]*arr[k] + dp[k][j];
                    dp[i][j] = max(dp[i][j],curr);
                }
            }
        }
        // for(int i = 0;i<=n;i++){
        //     for(int j = 0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][n-1];
    }
};
