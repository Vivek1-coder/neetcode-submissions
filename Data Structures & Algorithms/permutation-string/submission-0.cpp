class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(char ch:s1){
            mp1[ch-'a']++;
        }

        int l = 0;
        int len = 0;
        int n = s1.size();
        for(int r = 0;r<s2.size();r++){
            mp2[s2[r]-'a']++;
            while(((r-l+1) > n) || (mp2[s2[r]-'a'] > mp1[s2[r]-'a'])){
                mp2[s2[l]-'a']--;
                l++;
            }
            
            if(r-l+1 == n) return true;
        }
        return false;
    }
};
