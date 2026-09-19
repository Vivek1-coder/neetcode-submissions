class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) return false;
        int[] mp = new int[26];
        int n = s.length();
        for(int i = 0;i<n;i++){
            mp[s.charAt(i)-'a']++;
            mp[t.charAt(i)-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(mp[i] != 0) return false;
        }
        return true;
    }
}
