class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;

        int ROWS = grid.size();
        int COLS = grid[0].size();

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(grid[r][c] == 2) {
                    q.push({r,c});
                }
                if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        while(fresh > 0 && !q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(const auto& dir : directions) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
