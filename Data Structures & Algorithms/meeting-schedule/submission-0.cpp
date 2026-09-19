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
            return a.end > b.end;
        }
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int n = intervals.size();
        int l = 0;
        int r = 1;
        while(r<n){
            if(intervals[r].start < intervals[l].end){
                return false;
            }else{
                l++;
                r++;
            }
        }
        return true;
    }
};
