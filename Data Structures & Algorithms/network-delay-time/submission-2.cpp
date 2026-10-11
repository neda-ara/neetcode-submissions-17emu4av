class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;

        for(int i=0; i<n-1; i++) {
            for(const auto& edge : times) {
                int u=edge[0], v=edge[1], t=edge[2];
                if(dist[u] != INT_MAX && dist[v] > dist[u] + t) {
                    dist[v] = dist[u] + t;
                }
            }
        }

        int max_time = *max_element(dist.begin()+1,dist.end());
        return max_time == INT_MAX ? -1 : max_time;
    }
};
