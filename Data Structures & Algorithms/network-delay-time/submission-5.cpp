class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;

        for(const auto& time : times) {
            edges[time[0]].push_back({time[1],time[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});

        unordered_set<int> visited;
        int t=0;

        while(!minHeap.empty()) {
            auto [time,node] = minHeap.top();
            minHeap.pop();

            if(visited.count(node)) {
                continue;
            }
            visited.insert(node);
            t = time;

            for(const auto& [nei,weight] : edges[node]) {
                if(!visited.count(nei)) {
                    minHeap.push({time+weight,nei});
                }
            }
        }

        return visited.size() == n ? t : -1;
    }
};
