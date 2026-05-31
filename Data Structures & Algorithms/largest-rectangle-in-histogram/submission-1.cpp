class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> rightMost(n,n);
        vector<int> leftMost(n,-1);
        stack<int> indices;

        // 1. Build leftMost
        for(int i=0; i<n; i++) {
            while(!indices.empty() && heights[i] <= heights[indices.top()]) {
                indices.pop();
            }
            if(!indices.empty()) {
                leftMost[i] = indices.top();
            }
            indices.push(i);
        }

        // 2. Empty stack
        while(!indices.empty()) {
            indices.pop();
        }

        // 3. Build rightMost
        for(int i=n-1; i>=0; i--) {
            while(!indices.empty() && heights[i] <= heights[indices.top()]) {
                indices.pop();
            }
            if(!indices.empty()) {
                rightMost[i] = indices.top();
            }
            indices.push(i);
        }

        // 4. Calculate area at each bar and track maximum
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int left = leftMost[i]+1;
            int right = rightMost[i]-1;
            int width = right - left + 1;

            int area = heights[i] * width;
            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};
