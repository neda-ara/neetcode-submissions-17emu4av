class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int sqs[9] = {0};

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch == '.') {
                    continue;
                }
                int val = ch - '1';
                int mask = 1 << val;

                int sqKey = (i/3)*3 + j/3;

                if(mask&rows[i] || mask&cols[j] || mask&sqs[sqKey]) {
                    return false;
                }

                rows[i] |= mask;
                cols[j] |= mask;
                sqs[sqKey] |= mask;
            }
        }
        return true;
    }
};
