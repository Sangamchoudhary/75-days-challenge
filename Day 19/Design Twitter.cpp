class Twitter {
private:
    unordered_map<int,unordered_set<int>> followers_map;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int timer;
public:
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        for(auto it : tweets[userId]){
            pq.push({it.first,it.second});
            if(pq.size() > 10) pq.pop();
        }
        
        for(auto user : followers_map[userId]){
            for(auto tweet : tweets[user]){
                pq.push({tweet.first,tweet.second});
                if(pq.size() > 10) pq.pop();
            }
        }
        
        while(pq.size()){
            int recent_tweet = pq.top().second; pq.pop();
            ans.push_back(recent_tweet);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers_map[followerId].erase(followeeId);
    }
};