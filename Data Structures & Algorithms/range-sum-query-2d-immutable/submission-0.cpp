class NumMatrix {
private:
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) : mat(matrix) {}
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int r=row1; r<=row2; r++) {
            for(int c=col1; c<=col2; c++) {
                sum += mat[r][c];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */