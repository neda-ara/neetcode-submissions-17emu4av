class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;
        
        vector<int> ls(n,-1); 
        vector<int> rs(n,n);
        stack<int> stk;

        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            ls[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while(stk.size()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            rs[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int width = rs[i] - ls[i] - 1;
            int curr_area = heights[i] * width;
            max_area = max(max_area,curr_area);
        }

        return max_area;
    }
};
