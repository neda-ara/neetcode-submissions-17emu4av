class Solution {
public:
    int ROWS, COLS;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS,vector<bool>(COLS,false));
        vector<vector<bool>> atlantic(ROWS,vector<bool>(COLS,false));
        queue<pair<int,int>> pacQ, atlQ;

        for(int r=0; r<ROWS; r++) {
            pacQ.push({r,0});
            atlQ.push({r,COLS-1});
        } 
        for(int c=0; c<COLS; c++) {
            pacQ.push({0,c});
            atlQ.push({ROWS-1,c});
        } 

        bfs(heights,pacQ,pacific);
        bfs(heights,atlQ,atlantic);

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

    void bfs(vector<vector<int>>& heights, queue<pair<int,int>>& oceanQ, vector<vector<bool>>& ocean) {
        while(!oceanQ.empty()) {
            auto [r,c] = oceanQ.front();
            oceanQ.pop();
            ocean[r][c] = true;

            for(auto& [dr,dc] : directions) {
                int nr = r+dr, nc = c+dc;
                if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    oceanQ.push({nr,nc});
                } 
            }
        }   
    }
};
