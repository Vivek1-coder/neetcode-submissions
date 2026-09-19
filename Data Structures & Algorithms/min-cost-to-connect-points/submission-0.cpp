class Solution {
public:
    vector<int> parent,rank;
    int findParent(int idx){
        if(parent[idx] == idx) return idx;
        return parent[idx] = findParent(parent[idx]);
    }

    void unite(int u,int v){
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({d,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        parent.resize(n);
        rank.resize(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = i;
        }

        int ans = 0;
        for(auto &edge:edges){
            int d = edge[0];
            int u = edge[1];
            int v = edge[2];
            u = findParent(u);
            v = findParent(v);
            if(u != v){
                unite(u,v);
                ans += d;
            }
        }
        return ans;
    }
};
