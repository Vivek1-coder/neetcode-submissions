class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st = 0;
        int end = heights.size()-1;
        int ans = 0;
        while(st < end){
            int curr = min(heights[st],heights[end])*(end-st);
            ans = max(ans,curr);
            if(heights[end] > heights[st]){
                st++;
            }
            else{
                end--;
            }
        }
        return ans;
    }
};
