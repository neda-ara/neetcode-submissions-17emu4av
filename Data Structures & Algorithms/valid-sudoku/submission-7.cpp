class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> rows(9,0), cols(9,0), squares(9,0);

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char boardVal = board[r][c];

                if(boardVal == '.') continue;

                int bitVal = boardVal - '1';
                int bit = 1 << bitVal;
                int sqNo = (r/3)*3 + (c/3);

                if((rows[r] & bit) || (cols[c] & bit) || (squares[sqNo] & bit)) {
                    return false;
                }

                rows[r] |= bit;
                cols[c] |= bit;
                squares[sqNo] |= bit;
            }
        }

        return true;
    }
};
