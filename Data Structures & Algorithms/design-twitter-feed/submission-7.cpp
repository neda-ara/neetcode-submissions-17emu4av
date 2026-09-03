class Twitter {
    int count;
    unordered_map<int,vector<pair<int,int>>> tweetMap; // O(N.T)
    unordered_map<int,unordered_set<int>> followMap; // O(N.M)

public:
    Twitter(): count(0) {};
    
    void postTweet(int userId, int tweetId) { // O(1)
        tweetMap[userId].push_back({count--,tweetId}); 
        if(tweetMap[userId].size() > 10) {
            tweetMap[userId].erase(tweetMap[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>> minHeapFeed;
        
        followMap[userId].insert(userId); // O(1)

        if(followMap[userId].size() > 10) {
            priority_queue<
                vector<int>,
                vector<vector<int>>,
                greater<vector<int>>> minHeap;

            for(auto f : followMap[userId]) {
                if(!tweetMap.count(f)) {
                    continue;
                }
                int idx = tweetMap[f].size() - 1;
                auto &p = tweetMap[f][idx];
                minHeap.push({
                    p.first,p.second,f,idx-1
                });
                if(minHeap.size() > 10) {
                    minHeap.pop();
                }
            }
            while(!minHeap.empty()) {
                minHeapFeed.push(minHeap.top());
                minHeap.pop();
            }
        } else {
            for(auto f : followMap[userId]) {
                if(!tweetMap.count(f)) {
                    continue;
                }
                int idx = tweetMap[f].size() - 1;
                auto &p = tweetMap[f][idx];
                minHeapFeed.push({p.first,p.second,f,idx-1});
            }
        }

        vector<int> feed;
        while(!minHeapFeed.empty() && feed.size() < 10) {
            auto t = minHeapFeed.top();
            minHeapFeed.pop();
            feed.push_back(t[1]);

            int idx = t[3];
            if(idx >= 0) {
                auto &p = tweetMap[t[2]][idx];
                minHeapFeed.push({p.first,p.second,t[2],idx-1});
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
