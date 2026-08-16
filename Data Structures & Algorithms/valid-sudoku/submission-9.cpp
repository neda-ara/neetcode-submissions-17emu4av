class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols, squares;
        
        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char cell = board[r][c];
                int squareNo = (r/3)*3 + c/3;

                if(cell == '.') {
                    continue;
                }

                if(rows[r].count(cell) || cols[c].count(cell) || 
                    squares[squareNo].count(cell)) {
                        return false;
                }

                rows[r].insert(cell);
                cols[c].insert(cell);
                squares[squareNo].insert(cell);
            }
        }
        return true;
    }
};
