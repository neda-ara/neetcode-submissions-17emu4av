class Twitter {
    int time;
    unordered_map<int,unordered_set<int>> followMap;
    unordered_map<int,vector<pair<int,int>>> tweetMap;

public:
    Twitter(): time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        for(auto tweet : tweetMap[userId]) {
            minHeap.push(tweet);
            if(minHeap.size() > 10) {
                minHeap.pop();
            }
        }

        for(int followeeId : followMap[userId]) {
            for(auto tweet : tweetMap[followeeId]) {
                minHeap.push(tweet);
                if(minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
        }

        vector<int> my_feed;
        for(int i=0; minHeap.size()>0; i++) {
            my_feed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(my_feed.begin(), my_feed.end());
        return my_feed;
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
