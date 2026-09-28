class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       // maintain a monotonic stack with heights in increasing order
       // the stack will store a pair of {idx,height} : idx represents the index to which this height bar can extend back to be considered the largest possible rectangle 
       // every time a taller bar is encountered than previously stored, we pop the top stack eleement calculate its area and update global max_area
       // for all remaining elements in stack it means we never found a right boundary for them and use n as right idx to calculate their area
       // if for any bar no left boundary exists the stack becomes empty and we use - 1 as left index

        int n = heights.size(), area_max = 0;

        stack<pair<int,int>> stk;

        for(int i=0; i<n; i++) {
            int startIdx = i;
            while(!stk.empty() && heights[i] < stk.top().second) {
                auto [idx,h] = stk.top();
                stk.pop();
                int left = idx;
                int right = i;
                int w = right - left;
                int area = h * w;
                area_max = max(area_max,area);
                startIdx = idx;
            }
            stk.push({startIdx,heights[i]});
        }

        while(!stk.empty()) {
            auto [idx,h] = stk.top();
            int w = n - idx;
            int area = h * w;
            area_max = max(area_max,area);
            stk.pop();
        }
        
        return area_max;
    }
};
