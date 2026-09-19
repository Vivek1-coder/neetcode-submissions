class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> mp = new HashSet<>();
        for(int num:nums){
            mp.add(num);
        }
        int ans = 0;
        for(int num:mp){
            if(mp.contains(num+1)) continue;
            int temp = num;
            int cnt = 0;
            while(mp.contains(temp)){
                cnt++;
                temp--;
            }
            ans = Math.max(cnt,ans);
        }
        return ans;
    }
}
