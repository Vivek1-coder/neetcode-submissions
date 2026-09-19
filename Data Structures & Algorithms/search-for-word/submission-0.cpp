class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    bool search(vector<vector<char>> &board,int i,int j,string &word,int idx){
        if(idx == word.size()) return true;
        char ch = board[i][j];
        board[i][j] = '#';
        for(auto &[dx,dy]:dirs){
            int nx = i+dx;
            int ny = j+dy;
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()
             && board[nx][ny] == word[idx]){
                if(search(board,nx,ny,word,idx+1)) return true;
             }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[0] && search(board,i,j,word,1)){
                    return true;
                }
            }
        }
        return false;
    }
};
