class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for(int i = 0;i<strs.size();i++){
            int n = strs[i].size();
            ans += to_string(n);
            ans += '#';
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(int i = 0;i<s.size();){
            int n = 0;
            while(s[i] != '#'){
                n = (n*10) + (s[i]-'0');
                i++;
            }
            i++;
            string temp = "";
            while(temp.size() < n){
                temp += s[i];
                i++;
            }
            // i++;
            ans.push_back(temp);
        }
        return ans;
    }
};
