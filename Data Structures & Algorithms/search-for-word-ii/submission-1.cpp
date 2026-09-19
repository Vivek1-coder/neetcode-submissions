class Solution {
public:
    vector<pair<int,int>> dirs = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    bool search(vector<vector<char>> &board,string &word,int r,int c,int idx){
        if(idx == word.size()) return true;
        bool b = false;
        char ch = board[r][c];
        board[r][c] = '#';
        for(auto [dx,dy]:dirs){
            int nx = r+dx;
            int ny = c+dy;
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size()
            && word[idx] == board[nx][ny]){
                 b = search(board,word,nx,ny,idx+1);
                if(b) break;
            }
        }
        board[r][c] = ch;
        return b;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        for(string &word:words){
            bool found = false;
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    if(board[i][j] == word[0]){
                        if(search(board,word,i,j,1)){
                            ans.push_back(word);
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
                if(found) break;
            }
        }
        return ans;
    }
};
