class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), area_max = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int startIdx = i;

            while(!stk.empty() && heights[i] <= stk.top().first) {
                auto [height, idx] = stk.top();
                stk.pop();

                int w = i - idx;
                int area = height * w;
                area_max = max(area_max, area);
                startIdx = idx;
            }
            stk.push({heights[i],startIdx});
        }

        
        while(stk.size()) {
            auto [height,idx] = stk.top();
            int w = n - idx;
            int area = height * w;
            area_max = max(area_max, area);

            stk.pop();
        }
        
        return area_max;
    }
};
