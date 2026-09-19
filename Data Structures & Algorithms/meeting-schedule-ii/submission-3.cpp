/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st;
        vector<int> end;
        for(auto &interval:intervals){
            st.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(st.begin(),st.end());
        sort(end.begin(),end.end());
        int i = 0,j = 0;
        int n = intervals.size();
        int ans = 0;
        int curr = 0;
        while(i<n && j<n){
            if(st[i] < end[j]){
                curr++;
                i++;
            }else{
                curr--;
                j++;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};
