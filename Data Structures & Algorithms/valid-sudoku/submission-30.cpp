class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows, cols, sqs;

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                char ch = board[r][c];
                if(ch =='.') {
                    continue;
                }

                int sqKey = (r/3)*3 + c/3;

                if(rows[r].count(ch) || cols[c].count(ch) || sqs[sqKey].count(ch)) {
                    return false;
                }

                rows[r].insert(ch);
                cols[c].insert(ch);
                sqs[sqKey].insert(ch);
            }
        }

        return true;
    }
};
