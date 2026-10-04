class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, bottom = m-1;

        while(top <= bottom) {
            int mid = top + (bottom-top)/2;

            if (matrix[mid][0] > target) {
                bottom = mid - 1;
            } else if(matrix[mid][n-1] < target) {
                top = mid + 1;
            } else {
                break;
            }
        }

        if(top > bottom) {
            return false;
        }

        int l = 0, r = n-1;
        int row = top + (bottom-top)/2;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                l++;
            } else {
                r--;
            }
        }

        return false;
    }
};
