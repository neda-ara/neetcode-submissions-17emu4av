class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area = 0;

        stack<int> stk;
        vector<int> left(n,-1);
        vector<int> right(n,n);

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
            int currArea = heights[i] * (right[i] - left[i] - 1);
            area = max(area,currArea);
        }
        return area;
    }
};
