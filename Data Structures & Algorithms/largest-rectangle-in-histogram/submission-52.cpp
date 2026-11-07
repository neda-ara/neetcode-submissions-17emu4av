class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), largest_area = 0;

        stack<int> stk;

        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && (i==n || heights[i] < heights[stk.top()])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                largest_area = max(h*w, largest_area);
            }
            stk.push(i);
        }

        return largest_area;
    }
};
