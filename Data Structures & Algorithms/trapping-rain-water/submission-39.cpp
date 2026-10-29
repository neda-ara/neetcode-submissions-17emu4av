class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size(), water = 0;

        if(n == 0) {
            return 0;
        }

        stack<int> stk;

        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[i] > heights[stk.top()]) {
                int mid = heights[stk.top()];
                stk.pop();

                if(!stk.empty()) {
                    int h = min(heights[i],heights[stk.top()]) - mid;
                    int w = i - stk.top() - 1;
                    water += h*w;
                }
            }
            stk.push(i);
        }

        return water;
    }
};
