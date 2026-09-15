class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        backtrack(0,board);
        return res;
    }

    void backtrack(int r, vector<string>& board) {
        int n = board.size();
        if(r == n) {
            res.push_back(board);
            return;
        }

        for(int c=0; c<n; c++) {
            if(isSafe(r,c,board)) {
                board[r][c] = 'Q';
                backtrack(r+1,board);
                board[r][c] = '.';
            }
        }
    }

    bool isSafe(int r, int c, vector<string>& board) {
        for(int i=r-1; i>=0; i--) {
            if(board[i][c] == 'Q') {
                return false;
            }
        }
        for(int i=r-1,j=c-1; i>=0 && j>=0; i--,j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i=r-1,j=c+1; i>=0 && j<board.size(); i--,j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
