class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        stack<int> stk;

        for(int i=0; i<n; i++) {
            while(!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = height[stk.top()];
                stk.pop();
                if(!stk.empty()) {
                    int right = height[i];
                    int left = height[stk.top()];
                    int h = min(left,right) - mid;
                    int w = i - stk.top() - 1;
                    water += h*w;
                }
            }
            stk.push(i);
        }
        return water;
    }
};
