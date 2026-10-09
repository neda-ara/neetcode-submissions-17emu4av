class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto& time : times) { // O(E) -> E:edges = times.size()
            adj[time[0]].push_back({time[1],time[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dfs(k,0,adj,dist); // O(V.E)

        int maxTime = *max_element(dist.begin()+1,dist.end()); // O(V) -> V:vertices = n
        return maxTime == INT_MAX ? -1 : maxTime;
    }

    void dfs(int node, int time, unordered_map<int,vector<pair<int,int>>>& adj, vector<int>& dist) {
        if(time >= dist[node]) {
            return;
        }

        dist[node] = time;

        for(auto& [nei,t] : adj[node]) {
            dfs(nei,t+time,adj,dist);
        }
    }
};
