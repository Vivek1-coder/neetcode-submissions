class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
           if(board[i][0] == 'O'){
            q.push({i,0});
            board[i][0] = '#';
           }
           if(board[i][m-1] == 'O'){
            q.push({i,m-1});
                board[i][m-1] = '#';
           }
        }
        for(int j = 1;j<m-1;j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                    board[0][j] = '#';
            }
            if(board[n-1][j] == 'O'){
                q.push({n-1,j});
                    board[n-1][j] = '#';
            }
        }

        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int nx = i+dx;
                int ny = j+dy;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 'O'){
                    board[nx][ny] = '#';
                    q.push({nx,ny});
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
