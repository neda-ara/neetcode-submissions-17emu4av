class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows,cols,squares;

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char cell = board[r][c];
                if(cell == '.') {
                    continue;
                }

                int sqKey = (r/3)*3 + c/3;

                if(rows[r].count(cell) || cols[c].count(cell) || squares[sqKey].count(cell)) {
                    return false;
                }

                rows[r].insert(cell);
                cols[c].insert(cell);
                squares[sqKey].insert(cell);
            }
        }
        return true;
    }
};
