class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int maxi = 0;
        vector<int> mp(26,0);
        int maxLen = 0;
        for(int r = 0;r<n;r++){
            mp[s[r]-'A']++;
            maxi = max(maxi,mp[s[r]-'A']);
            while((r-l+1-maxi) > k){
                mp[s[l]-'A']--;
                maxi = *max_element(mp.begin(),mp.end());
                l++;
            }
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};
