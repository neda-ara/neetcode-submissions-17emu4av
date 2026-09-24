class DSU {
public: 
    vector<int> Parent, Size;

    DSU(int n) {
        Parent.resize(n+1);
        Size.resize(n+1,1);

        for(int i=0; i<=n; i++) {
            Parent[i] = i;
        }
    }

    int find(int node) {
        if(Parent[node] != node) {
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) {
            return false;
        }

        if(Size[pu] > Size[pv]) {
            Size[pu] += Size[pv];
            Parent[pv] = pu;
        } else {
           Size[pv] += Size[pu];
            Parent[pu] = pv; 
        }
        return true;
    }

    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size(), COLS = board[0].size();
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        DSU dsu(ROWS*COLS + 1);

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(board[r][c] != 'O') {
                    continue;
                }
                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1) {
                    dsu.unionNodes(ROWS*COLS, r*COLS + c);
                } else {
                    for(const auto& [dr,dc] : directions) {
                        int nr = r+dr, nc = c+dc;
                        if(board[nr][nc] == 'O') {
                            dsu.unionNodes(r*COLS+c,nr*COLS+nc);
                        }
                    }
                }
            }
        }
        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                if(board[r][c] == 'O' && !dsu.connected(ROWS* COLS, r*COLS+c)) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
