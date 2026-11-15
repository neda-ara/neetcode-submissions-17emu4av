class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), rect_area_max = 0;

        stack<pair<int,int>> stk;
        
        for(int i=0; i<n; i++) {
            int startIdx = i;
            while(!stk.empty() && heights[i] < stk.top().first) {
                auto [h, idx] = stk.top();
                stk.pop();
                startIdx = idx;
                rect_area_max = max(rect_area_max, h*(i - idx));
            }
            stk.push({heights[i], startIdx});
        }

        while(stk.size()) {
            auto [h, idx] = stk.top();
            stk.pop();
            rect_area_max = max(rect_area_max, h*(n - idx));
        }

        return rect_area_max;
    }
};
