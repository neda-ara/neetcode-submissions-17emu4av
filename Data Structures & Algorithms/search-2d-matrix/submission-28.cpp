class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m*n-1;

        while(l <= r) {
            int mid = l + (r-l)/2;
            int row = mid/n, col = mid%n;

            if (matrix[row][col] == target) {
                return true;
            } else if(matrix[row][col] < target) {
                l++;
            } else {
                r--;
            }
        }

        return false;
    }
};
