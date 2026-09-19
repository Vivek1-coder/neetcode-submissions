class Solution {
public:
    vector<pair<int,int>> dirs = {
        {1,0},{-1,0},{0,-1},{0,1}
    };

    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      vector<vector<int>> dist(n,vector<int>(n,1e8));
      priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
      dist[0][0] = grid[0][0];
      pq.push({grid[0][0],0,0}); 
      while(!pq.empty()){
        int prev = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if(x == n-1 && y == n-1){
            return dist[n-1][n-1];
        }
        if(dist[x][y] < prev) continue;

        for(auto &[dx,dy]:dirs){
            int nx = x+dx;
            int ny = y+dy;
            if(nx >= 0 &&  ny >= 0 && ny < n && nx < n){
                int currDist = max(prev,grid[nx][ny]);
                if(currDist < dist[nx][ny]){
                    dist[nx][ny] = currDist;
                    pq.push({currDist,nx,ny});
                }
            }
        }
      }
     
      return dist[n-1][n-1];
    }
};
