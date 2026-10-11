class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj(n);

        for(const auto& time : times) {
            adj[time[0]].emplace_back(time[1],time[2]);
        }

        unordered_map<int,int> dist;
        for(int i=1; i<=n; i++) {
            dist[i] = INT_MAX;
        }

        dist[k] = 0;

        queue<pair<int,int>> q;
        q.emplace(k,0);

        while(!q.empty()) {
            auto [node,time] = q.front();
            q.pop();

            if(dist[node] < time) {
                continue;
            }

            for(const auto& [nei,w] : adj[node]) {
                if(dist[nei] > w+time) {
                    dist[nei] = w+time;
                    q.emplace(nei,w+time);
                }
            }
        }

        int res = 0;
        for(const auto& [node,time] : dist) {
            res = max(time,res);
        }

        return res == INT_MAX ? -1 : res;

    }
};
