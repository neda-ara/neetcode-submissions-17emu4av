class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            unordered_set<char> seen;
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') {
                    continue;
                }
                if (seen.count(ch)) {
                    return false;
                }
                seen.insert(ch);
            }
        }

        for (int c = 0; c < 9; c++) {
            unordered_set<char> seen;
            for (int r = 0; r < 9; r++) {
                char ch = board[r][c];
                if (ch == '.') {
                    continue;
                }
                if (seen.count(ch)) {
                    return false;
                }
                seen.insert(ch);
            }
        }

        for (int sq = 0; sq < 9; sq++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int r = (sq / 3) * 3 + i;
                    int c = (sq % 3) * 3 + j;

                    char ch = board[r][c];
                    if (ch == '.') {
                        continue;
                    }
                    if (seen.count(ch)) {
                        return false;
                    }
                    seen.insert(ch);
                }
            }
        }

        return true;
    }
};
