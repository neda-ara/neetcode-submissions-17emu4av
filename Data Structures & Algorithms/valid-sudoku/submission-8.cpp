class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0; row<9; row++) {
            unordered_set<char> seen;
            for(int i=0; i<9; i++) {
                char cell = board[row][i];
                if(cell == '.') {
                    continue;
                }
                if(seen.count(cell)) {
                    return false;
                }
                seen.insert(cell);
            }
        }

        for(int col=0; col<9; col++) {
            unordered_set<char> seen;
            for(int i=0; i<9; i++) {
                char cell = board[i][col];
                if(cell == '.') {
                    continue;
                }
                if(seen.count(cell)) {
                    return false;
                }
                seen.insert(cell);
            }
        }

        for(int square=0; square<9; square++) {
            unordered_set<char> seen;
            for(int r=0; r<3; r++) {
                for(int c=0; c<3; c++) {
                    int row = (square / 3) * 3 + r;
                    int col = (square % 3) * 3 + c;
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
