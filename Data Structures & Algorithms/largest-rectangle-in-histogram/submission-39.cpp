class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_mx = 0;

        stack<pair<int, int>> stk;

        for (int i = 0; i < n; i++) {
            int startIdx = i;
            while (!stk.empty() && heights[i] < stk.top().first) {
                auto [h, idx] = stk.top();
                stk.pop();
                int w = i - idx;
                area_mx = max(h*w, area_mx);
                startIdx = idx;
            }
            stk.push({heights[i],startIdx});
        }

        while(stk.size()) {
            auto [h,idx] = stk.top();
            stk.pop();
            area_mx = max(h*(n-idx), area_mx);
        }

        return area_mx;
    }
};
