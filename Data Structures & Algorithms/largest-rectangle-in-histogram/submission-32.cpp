class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;
        
        stack<int> stk;

        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i == n || heights[i] <= heights[stk.top()])) {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                max_area = max(max_area,height*width);
            }
            stk.push(i);
        }

        return max_area;
    }
};
