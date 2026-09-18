class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = (l+r) >> 1;
            int row = mid / n, col = mid % n;

            if(target > matrix[row][col]) {
                l = mid + 1;
            } else if (target < matrix[row][col]) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
