class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n,vector<int>(k+2,INF));

        for(auto& flight : flights) {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }

        dist[src][0] = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> minHeap;
        minHeap.push({0,src,-1});

        while(!minHeap.empty()) {
            auto [cost,source,stops] = minHeap.top();
            minHeap.pop();

            if(source == dst) {
                return cost;
            }
            if(stops == k || dist[source][stops+1] < cost) {
                continue;
            }

            for(auto& [nei,fare] : adj[source]) {
                int nextCost = cost + fare;
                int stopsToNext = stops+1;
                if(dist[nei][stopsToNext+1] > nextCost) {
                    dist[nei][stopsToNext+1] = nextCost;
                    minHeap.emplace(nextCost,nei,stopsToNext);
                }
            }
        }

        return -1;
    }
};
