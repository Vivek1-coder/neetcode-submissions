class Solution {
public:
    bool isPossible(vector<int> &piles,long long  h,long long k)
    {   
        long long curr = 0;
        for(int pile:piles){
            long long t = ((long long)(1LL*pile-1LL))/k + 1;
            curr += t;
            if(curr > h){
                return false;
            }
        }
        return true;
    }   
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        long long st = 1;
        long long end = 0;
        for(int pile:piles){
            end += 1LL*pile;
        }
        while(st <= end){
            long long mid = end - (end-st)/2;
            if(isPossible(piles,h,mid)){
                end = mid-1;
                ans = mid;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};
