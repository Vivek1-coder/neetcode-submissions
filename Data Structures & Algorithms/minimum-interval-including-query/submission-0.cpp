class Solution {
public:

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
       vector<vector<int>> arr;
       for(auto &interval:intervals){
        arr.push_back({interval[0],0,interval[1]});
       }
       for(int i = 0;i<queries.size();i++){
        int q = queries[i];
        arr.push_back({q,1,i});
       }
       sort(arr.begin(),arr.end());

       int n = queries.size();
       vector<int> ans(n,0);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
       for(int i = 0;i<arr.size();i++){
        if(arr[i][1] == 0){
            int t = arr[i][2]-arr[i][0] + 1;
            // cout<<arr[i][0]<<" ";
            pq.push({t,arr[i][2]});
        }else{
            int q = arr[i][0];
            // cout<<"q"<<q<<" ";
            int idx = arr[i][2];

            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }

            if(!pq.empty()){
                ans[idx] = pq.top().first;
            }else{
                ans[idx] = -1;
            }
        }
       }
       return ans;
    }
};
