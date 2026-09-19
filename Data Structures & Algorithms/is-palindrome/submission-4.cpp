class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r){
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(l<r && !isalnum(s[r])){
                r--;
            }

            if(s[l] == s[r]){
                l++;
                r--;
                continue;
            }else if(!isdigit(s[l]) && !isdigit(s[r]) && tolower(s[l]) == tolower(s[r])){
                l++;
                r--;
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
};
