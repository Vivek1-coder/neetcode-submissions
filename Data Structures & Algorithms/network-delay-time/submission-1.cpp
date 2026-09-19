class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        dist[k] = 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &time:times){
            int ui = time[0];
            int vi = time[1];
            int ti = time[2];
            adj[ui].push_back({vi,ti});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [t,u] = pq.top();
            pq.pop();
            if(t > dist[u]) continue;
            for(auto [v,ti]:adj[u]){
                if(dist[u]+ti < dist[v]){
                    dist[v] = dist[u]+ti;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(dist[i] >= 1e8) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
