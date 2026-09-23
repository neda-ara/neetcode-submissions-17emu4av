class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int start = i;
            while(!stk.empty() && heights[i] < stk.top().second) {
                auto [idx,h] = stk.top();
                max_area = max(max_area, h * (i-idx));
                start = idx;
                stk.pop();
            }
            stk.push({start,heights[i]});
        }

        while(!stk.empty()) {
            auto [idx,h] = stk.top();
            int area = h * (n-idx);
            max_area = max(max_area,area);
            stk.pop();
        }
        
        return max_area;
    }
};
