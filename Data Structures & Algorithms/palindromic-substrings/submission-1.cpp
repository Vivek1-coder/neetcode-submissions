class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> isPalin(n+1,vector<int> (n+1,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            isPalin[i][i] = 1;
            ans++;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i+1 <= 2){
                        isPalin[i][j] = 1;
                        ans++;
                    }
                    else{
                        if(isPalin[i+1][j-1] == 1){
                            ans++;
                            isPalin[i][j] = 1;
                        }
                    }
                }
            }
        }
      
        return ans;
    }
};
