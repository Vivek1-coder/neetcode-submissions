class Solution {
public:
    void solve(int n,int open,string temp,vector<string> &ans){
        if(n == 0){
            ans.push_back(temp);
            return;
        }
        if(open < n) solve(n,open+1,temp+'(',ans);
        temp+=')';
        if(open > 0)solve(n-1,open-1,temp,ans);
        
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        solve(n,0,temp,ans);
        return ans;
    }
};
