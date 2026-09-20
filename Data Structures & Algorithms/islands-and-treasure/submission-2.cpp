class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        vector<vector<int>> directions {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto& dir : directions) {
                int r = row + dir[0];
                int c = col + dir[1];

                if(r<0 || c<0 || r>=m || c>=n || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r,c});
            }
        }
    }
};
