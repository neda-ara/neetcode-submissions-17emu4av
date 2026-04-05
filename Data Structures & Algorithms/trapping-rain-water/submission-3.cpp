class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        int water = 0, n = height.size();
        stack<int> stk;

        for(int i=0; i<n; i++) {
            while(!stk.empty() && height[i] >= height[stk.top()]) {
                int mid = height[stk.top()];
                stk.pop();

                if(!stk.empty()) {
                    int h = min(height[i],height[stk.top()]) - mid;
                    int w = i - stk.top() - 1;
                    water += h*w;
                }
            }
            stk.push(i);
        }
        return water;
    }
};
