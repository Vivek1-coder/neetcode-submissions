class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i = 0;i<stones.size();i++){
            pq.push({stones[i],i});
        }
        while(pq.size() > 1){
            auto [x,ix] = pq.top();
            pq.pop();
            auto [y,iy] = pq.top();
            pq.pop();
            if(x != y){
                int z = abs(x-y);
                pq.push({z,ix});
            }
        }
        return pq.empty()?0:pq.top().first;
    }
};
