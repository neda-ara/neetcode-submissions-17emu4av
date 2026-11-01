class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int startIdx = i;
            while(!stk.empty() && heights[i] < stk.top().first) {
                auto [h,idx] = stk.top();
                stk.pop();

                startIdx = idx;
                int curr = h * (i - idx);
                area = max(area,curr);
            }
            stk.push({heights[i],startIdx});
        }

        while(!stk.empty()) {
            auto [h,idx] = stk.top();
            int curr = h * (n - idx);
            area = max(area,curr);  
            stk.pop();
        }
        
        return area;
    }
};
