class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0) return false;

        unordered_map<int,int> mp;
        for(int h:hand){
            mp[h]++;
        }
        sort(hand.begin(),hand.end());
        int cnt = 0;
        int mini = hand[0];
        while(cnt < n){
            int newMini = INT_MAX;
            for(int i = 0;i<groupSize;i++){
                int t = i+mini;
                if(mp.count(t)){
                    mp[t]--;
                    if(mp[t] > 0){
                        if(newMini == INT_MAX){
                            newMini = t;
                        }
                    }
                    else{
                        mp.erase(t);
                    }
                }
                else{
                    return false;
                }
                cnt++;
            }
            if(newMini == INT_MAX && cnt<n){
                newMini = hand[cnt];
            }
            // cout<<mini<<" ";
            mini = newMini;
        }
       return true;
    }
};
