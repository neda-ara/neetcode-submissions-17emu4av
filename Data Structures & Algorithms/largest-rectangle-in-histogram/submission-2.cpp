class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        stack<pair<int,int>> pairs;

        for(int i=0; i<n; i++) {
            int start = i;
            while(!pairs.empty() && pairs.top().second > heights[i]) {
                pair<int,int> top = pairs.top();
                int index = top.first;
                int height = top.second;

                maxArea = max(maxArea,height * (i-index));
                start = index;
                pairs.pop();
            }
            pairs.push({start, heights[i]});
        }

        while(!pairs.empty()) {
            int index = pairs.top().first;
            int height = pairs.top().second;
            maxArea = max(maxArea, height * (n-index));
            pairs.pop();
        }
        return maxArea;
    }
};
