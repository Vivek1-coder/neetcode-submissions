class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>> pq;
        for(int i = 0;i<points.size();i++){
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            pq.push({dist,i});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            auto [db,idx] = pq.top();
            pq.pop();
            res.push_back({points[idx][0],points[idx][1]});
        }
        return res;
    }
};
