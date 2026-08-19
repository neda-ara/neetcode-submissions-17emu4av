class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows,cols,squares;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char cell = board[i][j];

                if(cell == '.') {
                    continue;
                }

                int sqKey = (i/3)*3 + (j/3); 

                if(rows[i].count(cell) || cols[j].count(cell) || squares[sqKey].count(cell)) {
                    return false;
                }

                rows[i].insert(cell);
                cols[j].insert(cell);
                squares[sqKey].insert(cell);
            }
        }
        return true;
    }
};
