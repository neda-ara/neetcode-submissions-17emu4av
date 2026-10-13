class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

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

        while(!stk.empty()) {
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
            int w = right[i] - left[i] - 1;
            int area = heights[i] * w;
            area_max = max(area_max, area);
        }
        return area_max;
    }
};
