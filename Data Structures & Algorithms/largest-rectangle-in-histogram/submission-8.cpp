class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        stack<int> st;

        for(int i=0; i<=n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea,h*w);
            }
            st.push(i);
        }
        return maxArea;
    }
};
