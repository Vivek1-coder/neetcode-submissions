class Solution {
public:
    bool isPossible(vector<string> &board,int r,int c,int n){
        for(int i = 0;i<n;i++){
            if(board[i][c] == 'Q') return false;
        }
        for(int j = 0;j<n;j++){
            if(board[r][j] == 'Q') return false;
        }
        int i = r-1;
        int j = c+1;
        while(i >= 0 && j >= 0 && i<n && j<n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        i = r+1;
        j = c-1;
        while(i >= 0 && j >= 0 && i<n && j<n){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        i = r-1;
        j = c-1;
        while(i >= 0 && j >= 0 && i<n && j<n){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = r+1;
        j = c+1;
        while(i >= 0 && j >= 0 && i<n && j<n){
            if(board[i][j] == 'Q') return false;
            i++;
            j++;
        }
        return true;
    }
    void solve(vector<string> &board,int r,int n,vector<vector<string>> &ans){
        if(r == n){
            ans.push_back(board);
            return;
        }
       for(int j = 0;j<n;j++){
            if(isPossible(board,r,j,n)){
                board[r][j] = 'Q';
                solve(board,r+1,n,ans);
                board[r][j] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,0,n,ans);
        return ans;
    }
};
