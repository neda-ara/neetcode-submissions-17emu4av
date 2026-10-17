class DSU {
public:
    vector<int> parent, rank;

    DSU(int n): parent(n), rank(n,1) {
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionize(int u, int v) {
        int pu = find(u), pv = find(v);

        if(pu == pv) {
            return false;
        }

        if(rank[pu] > rank[pv]) {
            rank[pu] += rank[pv];
            parent[pv] = pu;
        } else {
            rank[pv] += rank[pu];
            parent[pu] = pv;
        }

        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        DSU dsu(n);

        vector<array<int,3>> edges;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist,i,j});
            }
        }

        sort(edges.begin(),edges.end());

        int cost = 0;
        for(const auto& [dist,u,v] : edges) {
            if(dsu.unionize(u,v)) {
                cost += dist;
            }
        }

        return cost;
    }
};
