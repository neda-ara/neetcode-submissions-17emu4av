class Twitter {
    int time;
    unordered_map<int,vector<pair<int,int>>> tweetMap;
    unordered_map<int,unordered_set<int>> followMap;

public:
    Twitter(): time(0) {};
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>> all_posts = tweetMap[userId];
        
        for(auto followeeId : followMap[userId]) {
            all_posts.insert(
                all_posts.end(),
                tweetMap[followeeId].begin(),
                tweetMap[followeeId].end()
            );
        }
        sort(all_posts.rbegin(),all_posts.rend());

        vector<int> feed;
        for(int i=0; i<min(10,(int)all_posts.size()); i++) {
            feed.push_back(all_posts[i].second);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followMap[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
