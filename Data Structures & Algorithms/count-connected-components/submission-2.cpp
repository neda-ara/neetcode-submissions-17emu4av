class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);

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

    bool unionSets(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) {
            return false;
        }

        if(size[pv] > size[pu]) {
            swap(pu,pv);
        }
        parent[pv] = pu;
        size[pu] += size[pv];
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       DSU dsu(n);
       int comps = n;

        for(auto& edge : edges) {
            if(dsu.unionSets(edge[0],edge[1])) {
                comps--;
            }
        }

        return comps;
    }
};
