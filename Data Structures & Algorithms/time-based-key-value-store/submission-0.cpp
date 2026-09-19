class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp[key].empty()) return "";
        int st = 0;
        int end = mp[key].size() - 1;
        
        while(st <= end){
            int mid = (st+end)/2;
            cout<<st<<" "<<end<<endl;
            if(mp[key][mid].first <= timestamp){
               st = mid+1;
            }
            else{
               end = mid-1;
            }
        }
        
        if(st == 0) return "";
        return mp[key][st-1].second;
    }
};
