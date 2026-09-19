class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // int t = 0;
        vector<int> mp(26,0);
        for(int i = 0;i<tasks.size();i++){
            mp[tasks[i]-'A']++;
        }
        sort(mp.rbegin(),mp.rend());
        int t = mp[0]*(n+1) - n;
        int idle = t-mp[0];
        int grp = mp[0] - 1;
        for(int i = 1;i<26;i++){
            if(mp[i] == 0) break;
            idle -= min(grp,mp[i]);
        }
        return max(0,idle) + tasks.size();
    }
};
