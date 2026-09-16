class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int start = i;
            while(!stk.empty() && stk.top().second > heights[i]) {
                pair<int,int> top = stk.top();
                int idx = stk.top().first;
                int h = stk.top().second;
                int area = h * (i-idx);
                area_max = max(area,area_max);

                start = idx;
                stk.pop();
            }
            stk.push({start,heights[i]});
        } 

        while(!stk.empty()) {
            int idx = stk.top().first;
            int h = stk.top().second;
            int area = h * (n-idx);
            area_max = max(area,area_max);
            stk.pop();
        }    

        return area_max;
    }
};
