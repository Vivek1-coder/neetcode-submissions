class CountSquares {
public:
    unordered_map<int,unordered_map<int,int>> xy;
    unordered_map<int,unordered_map<int,int>> yx;
    CountSquares() { }
    
    void add(vector<int> point) {
        xy[point[0]][point[1]]++;
        yx[point[1]][point[0]]++;
        
    }
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;
        int t = 1;
        if(xy.count(x) && xy[x].count(y)){
            t = xy[x][y];
        }
        for(auto y_cord:xy[x]){
            int ny = y_cord.first;
            if(ny == y) continue;
            int fy = y_cord.second;
            for(auto x_cord:yx[y]){
                int nx = x_cord.first;
                int fx = x_cord.second;
                if(nx == x) continue;
                if(xy.count(nx) && xy[nx].count(ny)){
                    int f = xy[nx][ny];
                    cout<<nx<<" "<<ny<<" "<<f<<endl;
                    int curr = fx*fy*f*t;
                    ans += curr;
                }
            }
        }
        return ans;
    }
};
