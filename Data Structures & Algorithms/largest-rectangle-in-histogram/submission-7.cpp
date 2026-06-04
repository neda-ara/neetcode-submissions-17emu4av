class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { 
        int n = heights.size(), maxArea = 0;
        stack<pair<int,int>> st;

        for(int i=0; i<n; i++) {
            int start = i;

            while(!st.empty() && st.top().second >= heights[i]) {
                pair<int,int> top = st.top();
                int area = top.second * (i - top.first);
                maxArea = max(maxArea,area);
                start = top.first;
                st.pop();
            }
            st.push({start,heights[i]});
        }

        while(!st.empty()) {
            pair<int,int> top = st.top();
            int area = top.second * (n - top.first);
            maxArea = max(maxArea,area);
            st.pop();
        }  
        return maxArea;
    }
};
