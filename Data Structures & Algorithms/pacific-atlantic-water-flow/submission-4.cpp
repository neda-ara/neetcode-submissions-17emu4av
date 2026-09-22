class Solution {
public:
    int ROWS, COLS;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS,vector<bool> (COLS,false));
        vector<vector<bool>> atlantic(ROWS,vector<bool> (COLS,false));

        for(int r=0; r<ROWS; r++) {
            dfs(heights,r,0,pacific);
            dfs(heights,r,COLS-1,atlantic);
        }

        for(int c=0; c<COLS; c++) {
            dfs(heights,0,c,pacific);
            dfs(heights,ROWS-1,c,atlantic);
        }

        vector<vector<int>> res;
        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r,c});
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean) {
        ocean[r][c] = true;

        for(auto& [dr,dc] : directions) {
            int nr = r+dr, nc = c+dc;

            if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && !ocean[nr][nc] && 
               heights[nr][nc] >= heights[r][c]) {
                dfs(heights,nr,nc,ocean);
            }
        }
    }

};
