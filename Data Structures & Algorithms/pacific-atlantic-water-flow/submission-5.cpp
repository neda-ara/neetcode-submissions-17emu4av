class Solution {
public:
    int ROWS, COLS;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> pacific(ROWS,vector<bool> (COLS,false));
        vector<vector<bool>> atlantic(ROWS,vector<bool> (COLS,false));
        queue<pair<int,int>> pQ, aQ;

        for(int r=0; r<ROWS; r++) {
            pQ.push({r,0});
            aQ.push({r,COLS-1});
        }

        for(int c=0; c<COLS; c++) {
            pQ.push({0,c});
            aQ.push({ROWS-1,c});
        }

        bfs(heights,pacific,pQ);
        bfs(heights,atlantic,aQ);

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

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, queue<pair<int,int>>& q) {

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            ocean[r][c] = true;

            for(auto& [dr,dc] : directions) {
                int nr = r+dr, nc = c+dc;

                if(nr>=0 && nc>=0 && nr<ROWS && nc<COLS && !ocean[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {
                    q.push({nr,nc});
                   }
            }
        }
    }

};
