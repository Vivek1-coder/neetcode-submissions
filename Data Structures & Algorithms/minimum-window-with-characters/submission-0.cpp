class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        // cout<<"Hii"<<endl;
        if(s.size() < t.size()) return "";
        for(char ch:t){
            mp1[ch-'A']++;
        }
        int n = t.size();
        int match = 0;
        int len = 1e8;
        int l = 0;
        int st = -1;
        // cout<<l<<" "<<endl;
        for(int r = 0;r<s.size();r++){
            mp2[s[r]-'A']++;
            if(mp2[s[r]-'A'] <= mp1[s[r]-'A']){
                match++;
            }

            while(match == n){
                if(mp2[s[l]-'A'] <= mp1[s[l]-'A']){
                    match--;
                }
                if(r-l+1 < len){
                    len = r-l+1;
                    st = l;
                }
                mp2[s[l]-'A']--;
                l++;
              
            }
        }
 
        if(st == -1) return "";
        return s.substr(st,len);
    }
};
