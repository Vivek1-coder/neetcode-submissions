class Solution {
public:
    void solve(string &s,int idx,int st,vector<vector<string>> &ans,
    vector<vector<int>> &isPalin,vector<string> &temp,string t){
        if(idx == s.size()){
            if(st == idx) ans.push_back(temp);
            return ;
        }

        t += s[idx];
        if(isPalin[st][idx]){
            temp.push_back(t);
            solve(s,idx+1,idx+1,ans,isPalin,temp,"");
            temp.pop_back();
        }
        solve(s,idx+1,st,ans,isPalin,temp,t);
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> isPalin(n+1,vector<int> (n+1,0));
        for(int i = 0;i<n;i++){
            isPalin[i][i] = 1;
        }
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
                if(s[i] == s[j]){
                    if(j-i+1 <= 2){
                        isPalin[i][j] = 1;
                    }
                    else{
                        isPalin[i][j] = isPalin[i+1][j-1];
                    }
                } 
            }
        }
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        solve(s,0,0,ans,isPalin,temp,"");
        return ans;
    }
};
