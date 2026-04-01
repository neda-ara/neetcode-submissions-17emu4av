class NumMatrix {
    vector<vector<int>> prefixSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        prefixSum = vector<vector<int>>(rows, vector<int>(cols,0));

        for(int row=0; row<rows; row++) {
            prefixSum[row][0] = matrix[row][0];

            for(int col=1; col<cols; col++) {
                prefixSum[row][col] = prefixSum[row][col-1] + matrix[row][col];
            }

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;

        for(int row=row1; row<=row2; row++) {
            if(col1 < 1) {
                sum += prefixSum[row][col2];
            } else {
                sum += prefixSum[row][col2] - prefixSum[row][col1-1];
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