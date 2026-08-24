class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char cell = board[r][c];

                if(cell == '.') continue;

                int val = cell - '0';
                int mask = 1 << val;
                int sqNo = (r/3)*3 + c/3;

                if(rows[r] & mask || cols[c] & mask || squares[sqNo] & mask) {
                    return false;
                }

                rows[r] |= mask;
                cols[c] |= mask;
                squares[sqNo] |= mask;
            }
        }
        return true;
    }
};
