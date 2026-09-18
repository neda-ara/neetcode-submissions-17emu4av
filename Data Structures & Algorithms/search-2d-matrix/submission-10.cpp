class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, bottom = m-1;

        while(top <= bottom) {
            int mid = (top + bottom) >> 1;
            if(target > matrix[mid][n-1]) {
                top = mid + 1;
            } else if(target < matrix[mid][0]) {
                bottom = mid - 1;
            } else {
                break;
            }
        }

        if(top > bottom) {
            return false;
        }        

        int row = (top+bottom) >> 1;
        int l = 0, r = n-1;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(target > matrix[row][mid]) {
                l = mid + 1;
            } else if (target < matrix[row][mid]) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
