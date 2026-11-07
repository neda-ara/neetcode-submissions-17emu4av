class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), largest_area = 0;

        stack<pair<int, int>> stk;

        for (int i = 0; i < n; i++) {
            int startIdx = i;
            while (!stk.empty() && heights[i] < stk.top().first) {
                auto [h, idx] = stk.top();
                stk.pop();
                startIdx = idx;
                int curr_rect_area = h * (i - idx);
                largest_area = max(curr_rect_area, largest_area);
            }
            stk.push({heights[i], startIdx});
        }

        while (!stk.empty()) {
            auto [h, idx] = stk.top();
            stk.pop();

            int curr_rect_area = h * (n - idx);
            largest_area = max(curr_rect_area, largest_area);
        }

        return largest_area;
    }
};
