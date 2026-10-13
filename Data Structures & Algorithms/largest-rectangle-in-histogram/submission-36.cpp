class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

        stack<int> stk;

        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i == n || heights[i] <= heights[stk.top()])) {
                int h = heights[stk.top()];
                stk.pop();

                int w = stk.empty() ? i : i - stk.top() - 1;
                int area = h * w;
                area_max = max(area_max, area);
            }
            stk.push(i);
        }

        return area_max;
    }
};
