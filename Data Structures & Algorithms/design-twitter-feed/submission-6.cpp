class Twitter {
    int time;
    unordered_map<int,vector<vector<int>>> tweetMap; // O(N.T)
    unordered_map<int,unordered_set<int>> followMap; // O(N.M)

public:
    Twitter(): time(0) {};
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({++time,tweetId}); // O(1)
    }
    
    vector<int> getNewsFeed(int userId) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            decltype(compare)> maxHeap(compare);
        
        followMap[userId].insert(userId); // O(1)

        for(int followeeId : followMap[userId]) { // O(M)
            if(tweetMap.count(followeeId)) {
                const vector<vector<int>>& tweets = tweetMap[followeeId]; // O(t)
                int n = tweets.size() - 1;

                maxHeap.push({tweets[n][0], tweets[n][1], followeeId, n});
            }
        }

        vector<int> feed;
        while(!maxHeap.empty() && feed.size() < 10) {
            vector<int> curr = maxHeap.top();
            maxHeap.pop();
            feed.push_back(curr[1]);

            int idx = curr[3];
            if (idx > 0) {
                const vector<int>& tweet = tweetMap[curr[2]][idx-1];
                maxHeap.push({tweet[0],tweet[1],curr[2],idx-1});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            followMap[followerId].insert(followeeId);  // O(1)
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId); // O(1)
    }
};
