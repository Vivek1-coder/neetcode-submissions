class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> lcs(n+1,vector<int> (n+1,0));
        int maxLen = 1;
        int st = 0;
        for(int i = 0;i<=n;i++){
            lcs[i][i] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
            if(s[i] == s[j]){
                if(j-i+1 == 2){
                    lcs[i][j] = 2;
                }
                else{
                    if(lcs[i+1][j-1] != 0){
                         lcs[i][j] = lcs[i+1][j-1]+2;
                    }
                   
                }
            }
            if(maxLen < lcs[i][j]){
                    maxLen = lcs[i][j];
                    st = i;
                }
            }
        }


        return s.substr(st,maxLen);
    }
};
