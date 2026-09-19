class Solution {
public:
    char lower(char ch){
        if(isupper(ch))  return 'a'+(ch-'A');
        return ch;
    }
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size()-1;
        while(st<end){
            if(!isalnum(s[st])){
                st++;
                continue;
            }
            else if(!isalnum(s[end])){
                end--;
                continue;
            }
            else if(lower(s[st]) != lower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};
