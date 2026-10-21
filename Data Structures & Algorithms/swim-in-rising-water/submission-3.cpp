class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> visited;

        priority_queue<vector<int>,vector<vector<int>>,greater<>> minHeap;

        vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        minHeap.push({grid[0][0], 0, 0});
        visited.insert({0,0});

        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int t = curr[0], r = curr[1], c = curr[2];
            if(r == n-1 && c == n-1) {
                return t;
            }

            for(const auto& [dr,dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || visited.count({nr,nc})) {
                    continue;
                }
                visited.insert({nr,nc});
                minHeap.push({max(t,grid[nr][nc]), nr, nc});
            }
        }

        return -1;
    }
};
