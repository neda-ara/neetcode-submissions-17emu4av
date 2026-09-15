class Solution {
public:
    vector<bool> col, posDiag, negDiag;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        col.resize(n, false);
        posDiag.resize(2*n, false);
        negDiag.resize(2*n, false);

        backtrack(0, board);
        return res;
    }

    void backtrack(int r, vector<string>& board) {
        int n = board.size();

        if(r == n) {
            res.push_back(board);
            return;
        }
        for(int c=0; c<n; c++) {
            if(col[c] || posDiag[r+c] || negDiag[r-c+n]){
                continue;
            } 

            col[c] = true;
            posDiag[r+c] = true;
            negDiag[r-c+n] = true;
            board[r][c] = 'Q';

            backtrack(r+1, board);

            col[c] = false;
            posDiag[r+c] = false;
            negDiag[r-c+n] = false;
            board[r][c] = '.';
        }
    }
};
