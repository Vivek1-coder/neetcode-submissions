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
    static bool cmp(Interval &a,Interval &b){
        if(a.start == b.start){
            return a.end < b.end;
        }
        return (a.start) < (b.start);
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        int ans = 0;
        for(int i = 0;i<intervals.size();i++){
            int st = intervals[i].start;
            int end = intervals[i].end;
            while(!pq.empty() && st >= pq.top().first){
                pq.pop();
            }
            pq.push({end,i});
            ans = max(ans,(int)pq.size());
            cout<<ans<<" ";
        }
        return ans;
    }
};
