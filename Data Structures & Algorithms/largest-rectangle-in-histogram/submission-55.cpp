class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), rect_area_max = 0;

        stack<int> stk;
        
        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i == n || heights[i] < heights[stk.top()])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                rect_area_max = max(rect_area_max, h*w);
            }
            stk.push(i);
        }

        return rect_area_max;
    }
};
