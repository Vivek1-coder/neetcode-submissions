class Solution {
    int findMaxLen(String s,char ch,int k){
        int n = s.length();
        int l = 0;
        int cnt = 0;
        int ans = 0;
        for(int r = 0;r<n;r++){
            if(s.charAt(r) != ch){
                cnt++;
            }
            while(cnt > k){
                if(s.charAt(l) != ch){
                    cnt--;
                }
                l++;
            }
            ans = Math.max(ans,r-l+1);
        }
        return ans;
    }
    public int characterReplacement(String s, int k) {
        int n = s.length();
        int ans = 0;
        for(int i = 0;i<26;i++){
            char ch = (char)(i+'A');
            ans = Math.max(ans,findMaxLen(s,ch,k));
        }
        return ans;
    }
}
