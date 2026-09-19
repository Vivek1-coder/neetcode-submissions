class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l = 0;
        int n = s.length();
        Set<Character> mp = new HashSet<>();
        int ans = 0;
        for(int r = 0;r<n;r++){
            while(mp.contains(s.charAt(r))){
                mp.remove(s.charAt(l));
                l++;
            }
            mp.add(s.charAt(r));
            ans = Math.max(ans,r-l+1);
        }
        return ans;        
    }
}
