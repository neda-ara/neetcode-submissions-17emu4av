class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, bottom = m-1;

        while(top <= bottom) {
            int mid = top + (bottom-top)/2;

            if(matrix[mid][0] > target) {
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

        int row = top + (bottom-top)/2;
        int l = 0, r = n-1;

        while(l <= r) {
            int col = l + (r-l)/2;

            if(matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r--;
            } else {
                l++;
            }
        }
        

        return false;
    }
};
