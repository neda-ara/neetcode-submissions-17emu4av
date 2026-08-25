class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }

        stack<int> idx;
        int water = 0, n = height.size();

        for(int i=0; i<n; i++) {
            while(!idx.empty() && height[i] >= height[idx.top()]) {
                int mid = height[idx.top()];
                idx.pop();
                if(!idx.empty()) {
                    int right = height[i];
                    int left = height[idx.top()];
                    int h = min(right,left) - mid;
                    int w = i - idx.top() - 1;
                    water += (h*w);
                }
            }
            idx.push(i);
        }
        return water;
    }
};
