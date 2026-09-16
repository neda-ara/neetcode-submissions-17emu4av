class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

        vector<int> left_smaller(n,-1);
        vector<int> right_smaller(n,n);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                left_smaller[i] = stk.top();
            }
            stk.push(i);
        }

        while(stk.size()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if(!stk.empty()) {
                right_smaller[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int h = heights[i];
            int w = right_smaller[i] - left_smaller[i] - 1;
            area_max = max(area_max,h*w);
        }

        return area_max;
    }
};
