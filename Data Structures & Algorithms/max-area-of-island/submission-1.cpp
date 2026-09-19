class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    grid[i][j] = 2;
                    int sz = 0;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        sz++;
                        for(auto [dx,dy]:dirs){
                            int nx = x+dx;
                            int ny = y+dy;
                            if(nx >= 0 && ny >= 0 && nx < n && ny<m &&
                             grid[nx][ny] == 1){
                                q.push({nx,ny});
                                grid[nx][ny] = 2;
                            }
                        }
                    }
                    ans = max(ans,sz);
                }
            }
        }
        return ans;
    }
};
