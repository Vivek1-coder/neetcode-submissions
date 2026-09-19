class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> mp;
        for(int r = 0;r<n;r++){
            if(mp.count(s[r])){
                int idx = mp[s[r]];
                if(idx >= l){
                    l = idx+1;
                }
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
