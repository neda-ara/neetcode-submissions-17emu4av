class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(matrix[r][c] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};
