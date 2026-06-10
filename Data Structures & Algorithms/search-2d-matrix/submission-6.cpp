class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int l = 0, r = (rows * cols) - 1;

        while(l <= r) {
            int mid = (r-l)/2 + l;
            int midEl = matrix[mid/cols][mid%cols];

            if(target > midEl) {
                l = mid + 1;
            } else if(target < midEl) {
                r = mid - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
