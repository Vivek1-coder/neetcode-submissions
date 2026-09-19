class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int l = 0;
        int n = intervals.size();
        for(int r = 1;r<n;r++){
            if(intervals[r][0] <= intervals[l][1]){
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
        return intervals;
    }
};
