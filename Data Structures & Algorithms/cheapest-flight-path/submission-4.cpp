class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flight:flights){
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];
            adj[u].push_back({v,p});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        dist[src][0] = 0;
        pq.push({0,0,src});
        while(!pq.empty()){
            int currP = pq.top()[0];
            int currStops = pq.top()[1];
            int u = pq.top()[2];
            pq.pop();
            if(currStops >= k+1) continue;
            if(currP > dist[u][currStops]) continue;

            for(auto [v,p]:adj[u]){
                if(dist[v][currStops+1] > dist[u][currStops]+p){
                        dist[v][currStops+1] = dist[u][currStops]+p;
                        pq.push({dist[v][currStops+1],currStops+1,v});
                    
                }
            }
        }
        int mini = 1e9;
        for(int i = 0;i<=k+1;i++){
            mini = min(mini,dist[dst][i]);
        }
        return mini >= 1e9 ?-1:mini;
    }
};
