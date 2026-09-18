class Solution {
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[0].size(); c++) {
                if(grid[r][c] == 1) {
                    area = max(area,bfs(grid,r,c));
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int,int>> q;
        q.push({r,c});

        grid[r][c] = 0;
        int currArea = 1;

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(auto& d : directions) {
                int nr = node.first + d[0];
                int nc = node.second + d[1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() 
                && grid[nr][nc] == 1) {
                    currArea++;
                    q.push({nr,nc});
                    grid[nr][nc] = 0;
                }
            }
        }
        return currArea;
    }
};
