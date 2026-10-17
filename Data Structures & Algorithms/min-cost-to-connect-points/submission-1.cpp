class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<int,vector<pair<int,int>>> adj;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        unordered_set<int> visit;
        minHeap.push({0,0});

        int cost = 0;

        while(visit.size() < n) {
            auto [dist, i] = minHeap.top();
            minHeap.pop();

            if(visit.count(i)) {
                continue;
            }
            cost += dist;
            visit.insert(i);

            for(auto& [d,j] : adj[i]) {
                if(!visit.count(j)) {
                    minHeap.push({d,j});
                }
            }
        }
        return cost;
    }
};
