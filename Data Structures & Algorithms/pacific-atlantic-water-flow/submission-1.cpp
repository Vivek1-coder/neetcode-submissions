class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int,int>> dirs = {
            {0,1},{0,-1},{1,0},{-1,0}
        };
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<m;i++){
            q.push({0,i});
            vis[0][i] = 1;
        }
        for(int i = 1;i<n;i++){
            q.push({i,0});
            vis[i][0] = 1;
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] != 1 && 
                heights[nx][ny] >= heights[x][y]){
                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        for(int i = 0;i<m;i++){
            q.push({n-1,i});
            if(vis[n-1][i] == 1) vis[n-1][i] = 3;
            else vis[n-1][i] = 2;
        }
        for(int i = 0;i<n-1;i++){
            q.push({i,m-1});
            if(vis[i][m-1] == 1) vis[i][m-1] = 3;
            else vis[i][m-1] = 2;
        }

        // vis[n-1][0] = 3;
        // vis[0][m-1] = 3;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:dirs){
                int nx = x+dx;
                int ny = y+dy;
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && vis[nx][ny] != 2 && vis[nx][ny] != 3 &&
                heights[nx][ny] >= heights[x][y]){
                    q.push({nx,ny});
                    if(vis[nx][ny] == 1) vis[nx][ny] = 3;
                    else vis[nx][ny] = 2;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++){
                if(vis[i][j] == 3){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
