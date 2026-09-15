class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows,cols,sqs;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                char ch = board[i][j];
                if(ch == '.') {
                    continue;
                }

                int sqKey = (i/3)*3 + (j/3);

                if(rows[i].count(ch) || cols[j].count(ch) || sqs[sqKey].count(ch)) {
                    return false;
                }

                rows[i].insert(ch);
                cols[j].insert(ch);
                sqs[sqKey].insert(ch);
            }
        }

        return true;
    }
};
