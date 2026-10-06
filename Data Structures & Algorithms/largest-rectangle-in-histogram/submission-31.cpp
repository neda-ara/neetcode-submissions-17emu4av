class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;
        
        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int startIdx = i;

            while(!stk.empty() && heights[i] <= stk.top().first) {
                auto [height, idx] = stk.top();
                stk.pop();
                startIdx = idx;
                max_area = max(max_area,height*(i-idx));
            }
            stk.push({heights[i],startIdx});
        }

        while(stk.size()) {
            auto [height, idx] = stk.top();
            max_area = max(max_area,height*(n-idx));
            stk.pop();
        }

        return max_area;
    }
};
