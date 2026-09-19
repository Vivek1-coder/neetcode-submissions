class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = 0;
        int n = intervals.size();
        while(l<n && intervals[l][1] < newInterval[0]){
            l++;
        }

        if(l == n){
            intervals.push_back(newInterval);
            return intervals;
        }

        if(intervals[l][0] <= newInterval[1]){
            intervals[l][0] = min(newInterval[0],intervals[l][0]);
            intervals[l][1] = max(newInterval[1],intervals[l][1]);
            for(int r = l+1;r<n;r++){
                if(intervals[l][1] >= intervals[r][0]){
                    intervals[l][0] = min(intervals[l][0],intervals[r][0]);
                    intervals[l][1] = max(intervals[l][1],intervals[r][1]);
                }else{
                    l++;
                    intervals[l][0] = intervals[r][0];
                    intervals[l][1] = intervals[r][1];
                }
            }

            while(intervals.size() > (l+1)){
                intervals.pop_back();
            }
        }
        else{
            intervals.push_back(newInterval);
            int lft = n-1;
            int rgt = n;
            while(l <= lft){
                swap(intervals[lft--],intervals[rgt--]);
            }
        }
        return intervals;
    }
};
