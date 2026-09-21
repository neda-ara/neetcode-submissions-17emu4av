class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int fresh = 0, time = 0;
        queue<pair<int,int>> q;

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(grid[r][c] == 1) {
                    fresh++;
                }
                if(grid[r][c] == 2) {
                    q.push({r,c});
                }
            }
        }

        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(fresh > 0 && !q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto& dir: directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if(row>=0 && row<ROWS && col>=0 && col<COLS && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row,col});
                    } 
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
