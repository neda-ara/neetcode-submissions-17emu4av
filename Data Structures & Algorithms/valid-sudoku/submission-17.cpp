class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0; r<9; r++) {
            unordered_set<char> seen;
            for(int i=0; i<9; i++) {
                char cell = board[r][i];
                if(cell == '.') {
                    continue;
                }
                if(seen.count(cell)) {
                    return false;
                }
                seen.insert(cell);
            }
        }

        for(int c=0; c<9; c++) {
            unordered_set<char> seen;
            for(int i=0; i<9; i++) {
                char cell = board[i][c];
                if(cell == '.') {
                    continue;
                }
                if(seen.count(cell)) {
                    return false;
                }
                seen.insert(cell);
            }
        }

        for(int sq=0; sq<9; sq++) {
            unordered_set<char> seen;
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    int row = (sq/3)*3 + i;
                    int col = (sq%3)*3 + j;
                    char cell = board[row][col];

                    if(cell == '.') {
                        continue;
                    }

                    if(seen.count(cell)) {
                        return false;
                    }

                    seen.insert(cell);
                }
            }
        }

        return true;
    }
};
