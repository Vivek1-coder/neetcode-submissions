class Solution {
public:
    vector<pair<int,int>> dirs = {
        {-1,0},{1,0},{0,1},{0,-1}
    };
    int dfs(int x,int y,vector<vector<int>> &matrix,vector<vector<int>> &vis,int n,int m){
        int maxi = 0;
        vis[x][y] = 0;
        for(auto & [dx,dy]:dirs){
            int nx = x+dx;
            int ny = y+dy;
            if((nx >= 0) && (ny >= 0) && (nx<n) && (ny<m) && (matrix[nx][ny] > matrix[x][y])){
                if(vis[nx][ny] == -1){
                    int curr = dfs(nx,ny,matrix,vis,n,m);
                    maxi = max(maxi,curr);
                }else{
                    maxi = max(maxi,vis[nx][ny]);
                }
            }
        }
        vis[x][y] = maxi+1;
        return maxi+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n,vector<int> (m,-1));
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == -1){
                    dfs(i,j,matrix,vis,n,m);
                }
                ans = max(ans,vis[i][j]);
            }
        }
        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<m;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};
