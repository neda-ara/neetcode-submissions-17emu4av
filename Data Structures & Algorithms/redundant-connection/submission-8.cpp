class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1,1);

        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionByRank(int u, int v) {
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);

        for(const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if(!dsu.unionByRank(u,v)) {
                return {u,v};
            }
        }
        
        return {};
    }
};
