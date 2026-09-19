class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int dist = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int cnt = 0;cnt<sz;cnt++){
                 auto [i,j] = q.front();
                q.pop();
                for(auto [dx,dy]:dirs){
                    int nx = i+dx;
                    int ny = j+dy;
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] > dist){
                        grid[nx][ny] = dist;
                        q.push({nx,ny});
                    }
                }
            }
            dist++;
        }
    }
};
