class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int start = i;
            while(!stk.empty() && heights[i] < stk.top().second) {
                pair<int,int> top = stk.top();
                area = max(area, top.second * (i - top.first));
                start = top.first;
                stk.pop();
            } 
            stk.push({start,heights[i]});
        }

        while(!stk.empty()) {
            area = max(area,stk.top().second * (n-stk.top().first));
            stk.pop();
        }

        return area;
    }
};
