class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<int> nxt(n+2,0);
     
        nxt[0] = 1;
        for(int idx = n-1;idx>=0;idx--){
            vector<int> curr(n+2,0);
            for(int open = 0;open<n;open++){
                if(s[idx] == '('){
                    curr[open] |= nxt[open+1];
                }
                else if(s[idx] == ')'){
                    if(open-1 >= 0)
                        curr[open] = nxt[open-1];
                }
                else{
                    curr[open] = (nxt[open+1] | nxt[open]);
                    if(open-1 >= 0){
                        curr[open] |= nxt[open-1];
                    }
                }
            }
            nxt = curr;
            
        }
        // for(int i = 0;i<=n;i++){
        //     cout<<nxt[i]<<" ";
        // }
        return nxt[0];
    }
};
