class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), rect_area_max = 0;

        vector<int> left(n,-1);
        vector<int> right(n,n);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        while(stk.size()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            rect_area_max = max(rect_area_max, area);
        }

        return rect_area_max;
    }
};
