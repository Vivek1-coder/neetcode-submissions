class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>>dirs = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        queue<pair<int,int>> q;
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    q.push({i,j});
                    grid[i][j] = '#';
                    cout<<i<<" "<<j<<endl;
                    while(!q.empty()){
                        auto [i,j] = q.front();
                        q.pop();
                        for(auto [dx,dy]:dirs){
                            int nx = i+dx;
                            int ny = j+dy;
                            if(nx >= 0 && nx < n && ny >= 0 && ny < m && 
                            grid[nx][ny] == '1'){
                                grid[nx][ny] = '#';
                                q.push({nx,ny});
                            }
                        }
                    }
                    ans++;
                }
            }
           
        }
         return ans;
    }
};
