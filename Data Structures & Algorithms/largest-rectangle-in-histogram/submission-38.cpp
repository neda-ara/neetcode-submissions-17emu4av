class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_mx = 0;

        vector<int> ns_left(n,-1);
        vector<int> ns_right(n,n);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                stk.pop();
            }
            if(!stk.empty()) {
                ns_left[i] = stk.top();
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
                ns_right[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int left = ns_left[i], right = ns_right[i];
            int area = heights[i] * (right-left-1);
            area_mx = max(area,area_mx);
        }

        return area_mx;
    }
};
