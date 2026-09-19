class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        if(st.find(endWord) == st.end()) return 0;
        q.push(beginWord);
        int cnt = 1;
        unordered_set<string> visited;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                string wrd = q.front();
                // cout<<wrd<<" ";
                if(wrd == endWord) return cnt;
                q.pop();
                for(int i = 0;i<wrd.size();i++){
                    char ch = wrd[i];
                    for(int j = 0;j<26;j++){
                        char newch = 'a'+j;
                        if(newch == ch) continue;
                        wrd[i] = newch;
                        if(st.count(wrd) && !visited.count(wrd)){
                            q.push(wrd);
                            visited.insert(wrd);
                        }
                    }
                    wrd[i] = ch;
                }
            }
            if(q.empty()) return 0;
            cnt++;
        }
        return 0;
    }
};
