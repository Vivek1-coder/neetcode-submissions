class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suff(n+1,0);
        for(int i = n-1;i>=0;i--){
            suff[i] = max(suff[i+1],height[i]);
        }

        int ans = 0;
        int maxTillNow = height[0];
        for(int i = 1;i<n-1;i++){
            if(height[i] < maxTillNow){
                ans += ((min(maxTillNow,suff[i])) - height[i]);
            }
            maxTillNow = max(maxTillNow,height[i]);
        }
        return ans;
    }
};
