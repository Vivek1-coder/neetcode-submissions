class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int t;
    Twitter() {
        this->t = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        // cout<<userId<<"->";
        following[userId].insert(userId);
        for(int creator:following[userId]){
            // cout<<creator<<" ";
            int n = tweets[creator].size();
            for(int i = n-1;i>=n-10;i--){
                if(i<0) break;
                pq.push({tweets[creator][i].first,tweets[creator][i].second});
                if(pq.size() > 10) pq.pop();
            }
        }
        // cout<<endl;
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            auto [t,id] = pq.top();
            pq.pop();
            // cout<<id<<endl;
            ans.push_back(id);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followeeId].insert(followerId);
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followeeId].erase(followerId);
        following[followerId].erase(followeeId);
    }
};
