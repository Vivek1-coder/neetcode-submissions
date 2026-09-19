class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dirs = {
            {-1,0},{1,0},{0,1},{0,-1}
        };
        int t = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]:dirs){
                    int nx = x+dx;
                    int ny = y+dy;
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        q.push({nx,ny});
                        cnt--;
                        grid[nx][ny] = 2;
                    }
                }
            }
            t++;
        }

        return cnt == 0?max(0,t-1):-1;
    }
};
