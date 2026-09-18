class Solution {
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        for(int r=0; r<grid.size(); r++) {
            for(int c=0; c<grid[0].size(); c++) {
                if(grid[r][c] == 1) {
                    area = max(area,dfs(grid,r,c));
                }
            }
        }

        return area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() 
        || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int currArea = 1;

        for(auto& d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];
            currArea += dfs(grid,nr,nc);
        }
        return currArea;
    }
};
