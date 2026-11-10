class Solution {
   public:
    int trap(vector<int>& heights) {
        if (heights.empty()) {
            return 0;
        }

        int n = heights.size(), water = 0;

        vector<int> left(n, heights[0]);
        vector<int> right(n, heights[n - 1]);

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], heights[i]);
            right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
        }

        for (int i = 0; i < n; i++) {
            int leftmax = left[i], rightmax = right[i];
            water += min(leftmax, rightmax) - heights[i];
        }

        return water;
    }
};
