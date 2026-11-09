class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, bot = m-1;

        while(top <= bot) {
            int mid = top + (bot-top)/2;

            if(matrix[mid][0] > target) {
                bot = mid - 1;
            } else if (matrix[mid][n-1] < target) {
                top = mid + 1;
            } else {
                break;
            }
        }

        if(top > bot) {
            return false;
        }

        int row = top + (bot-top)/2;

        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(matrix[row][mid] == target) {
                return true;
            } else if(matrix[row][mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        

        return false;
    }
};
