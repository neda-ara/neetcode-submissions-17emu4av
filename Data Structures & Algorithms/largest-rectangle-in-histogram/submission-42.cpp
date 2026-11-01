class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        vector<int> ls(n,-1);
        vector<int> rs(n,n);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                ls[i] = stk.top();
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
                rs[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int curr = heights[i] * (rs[i] - ls[i] - 1);
            area = max(area,curr);
        }
        return area;
    }
};
