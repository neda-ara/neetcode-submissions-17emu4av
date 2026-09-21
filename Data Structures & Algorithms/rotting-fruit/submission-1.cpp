class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;

        int ROWS = grid.size();
        int COLS = grid[0].size();

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

        while(fresh > 0) {
            bool flag = false;
            for(int r=0; r<ROWS; r++) {
                for(int c=0; c<COLS; c++) {
                    if(grid[r][c] == 2) {
                        for(const auto& d : directions) {
                            int row = r + d.first;
                            int col = c + d.second;

                            if(row>=0 && row<ROWS && col>=0 &&  col<COLS 
                            && grid[row][col] == 1) {
                                grid[row][col] = 3;
                                fresh--;
                                flag = true;
                            }
                        }
                    }
                }
            }
            if(!flag) return -1;

            for(int r=0; r<ROWS; r++) {
                for(int c=0; c<COLS; c++) {
                    if(grid[r][c] == 3) {
                        grid[r][c] = 2;
                    }
                }
            }

            time++;
        }

        return time;
    }
};
