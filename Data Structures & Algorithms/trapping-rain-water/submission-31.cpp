class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        stack<int> stk;

        for(int i=0; i<n; i++) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int mid = height[stk.top()];
                stk.pop();
                if(!stk.empty()) {
                    int right = height[i], left = height[stk.top()];
                    int width = i - stk.top() - 1;
                    int bar_water = (min(left,right) - mid) * width;
                    water += bar_water;
                }
            }
            stk.push(i);
        }

        return water;
    }
};
