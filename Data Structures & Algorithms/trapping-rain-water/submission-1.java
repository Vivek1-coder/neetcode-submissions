class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int n = height.length;
        int[] suffMax = new int[n];
        suffMax[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            suffMax[i] = Math.max(height[i],suffMax[i+1]);
        }
        int prefMax = height[0];
        for(int i = 1;i<n-1;i++){
            prefMax = Math.max(height[i],prefMax);
            ans += Math.min(suffMax[i],prefMax) - height[i];
        }
        return ans;
    }
}
