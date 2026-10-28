class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = n-1;

        while(l < m && r >= 0) {
            if(matrix[l][r] == target) {
                return true;
            } else if (matrix[l][r] < target) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }
};
