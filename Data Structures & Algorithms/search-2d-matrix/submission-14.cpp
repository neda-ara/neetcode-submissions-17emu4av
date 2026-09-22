class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m-1;

        while(top <= bottom) {
            int mid = (bottom-top)/2 + top;

            if(matrix[mid][0] > target) {
                bottom = mid - 1;
            } else if (matrix[mid][n-1] < target) {
                top = mid+1;
            } else {
                break;
            }
        }

        if(top > bottom) {
            return false;
        }

        int row = (bottom-top)/2 + top;
        int l=0, r=n-1;

        while(l <= r) {
            int mid = (r-l)/2 + l;

            if(matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return false;
    }
};
