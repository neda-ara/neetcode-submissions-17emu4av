class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

        stack<int> stk;

        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i==n || heights[stk.top()] >= heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                area_max = max(area_max, h*w);
            }
            stk.push(i);
        }   

        return area_max;
    }
};
