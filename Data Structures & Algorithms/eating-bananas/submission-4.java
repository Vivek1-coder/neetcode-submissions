class Solution {
    boolean isPossible(int[] piles,int k,int h){
        int n = piles.length;
        for(int i = 0;i<n;i++){
            h -= ((piles[i]+k-1)/k);
            if(h < 0) return false;
        }
        return h >= 0;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int st = 1;
        int end = piles[0];
        for(int i = 0;i<n;i++){
            end = Math.max(end,piles[i]);
        }
        int ans = end;
        while(st <=end){
            int mid = (st+end)/2;
            if(isPossible(piles,mid,h)){
                end = mid-1;
                ans = mid;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
}
