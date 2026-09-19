class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2 != n3) return false;

        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        dp[0][0] = 1;

        for(int i = 0;i<=n1;i++){
            for(int j = 0;j<=n2;j++){
                if(i == 0 && j == 0) continue;
                int idx = i+j;
                if(i>=1 && s1[i-1] == s3[idx-1]){
                    dp[i][j] |= dp[i-1][j];
                }
                if(j>=1 && s2[j-1] == s3[idx-1]){
                    dp[i][j] |= dp[i][j-1];
                }
                // cout<<curr[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[n1][n2];
    }
};
