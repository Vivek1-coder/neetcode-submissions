class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>> nxtTim;
        priority_queue<vector<int>,vector<vector<int>>> freq;
        vector<vector<int>> mp(26,vector<int> (2,0));
        for(int i = 0;i<tasks.size();i++){
            mp[tasks[i]-'A'][0]++;
            mp[tasks[i]-'A'][1] = tasks[i]-'A';
        }
        for(int i = 0;i<26;i++){
            if(mp[i][0] == 0) continue;
            freq.push({mp[i][0],mp[i][1]});
        }
        int t = 1;
        while(!freq.empty() || !nxtTim.empty()){
            while(!nxtTim.empty() && nxtTim.top()[0] <= t){
                freq.push({nxtTim.top()[1],nxtTim.top()[2]});
                nxtTim.pop();
            }
            if(!freq.empty()){
                int f = freq.top()[0];
                int ch = freq .top()[1];
                freq.pop();
                if(f-1 > 0) nxtTim.push({t+n+1,f-1,ch});
            }
            else{
                t = nxtTim.top()[0] - 1;
            }
            t++;
        }
        return t-1;
    }
};
