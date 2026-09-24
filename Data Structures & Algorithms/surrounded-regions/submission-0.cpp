class Solution {
    int ROWS, COLS;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size(), COLS = board[0].size();

        for(int r=0; r<ROWS; r++) {
            if(board[r][0] == 'O') {
                capture(board,r,0);
            }
            if(board[r][COLS-1] == 'O') {
                capture(board,r,COLS-1);
            }
        }
        for(int c=0; c<COLS; c++) {
            if(board[0][c] == 'O') {
                capture(board,0,c);
            }
            if(board[ROWS-1][c] == 'O') {
                capture(board,ROWS-1,c);
            }
        }

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if(board[r][c] == 'T') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void capture(vector<vector<char>>& board, int r, int c) {
        if(r<0 || c<0 || r>=ROWS || c>=COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = 'T';

        for(const auto& [dr,dc] : directions) {
            capture(board,r+dr,c+dc);
        }
    }
};
