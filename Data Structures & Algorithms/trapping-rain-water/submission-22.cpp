class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        stack<int> idx;

        for(int i=0; i<n; i++) {
            while(!idx.empty() && height[i] >= height[idx.top()]) {
                int mid = height[idx.top()];
                idx.pop();
                if(!idx.empty()) {
                    int effH = min(height[i],height[idx.top()]);
                    int h = effH - mid;
                    int w = i - idx.top() - 1;
                    water += (h*w);
                }
            }
            idx.push(i);
        }
        return water;
    }
};
