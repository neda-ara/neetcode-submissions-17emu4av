class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }

        int n = height.size();
        vector<int> leftMax(n);

        leftMax[0] = height[0];
        for(int i=1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1],height[i]);
        }

        int total = 0, rightMax = height[n-1];
        for(int i=n-1; i>=0; i--) {
            if(height[i] > rightMax) {
                rightMax = height[i];
            }
            total += min(leftMax[i],rightMax) - height[i];
        }
        return total;
    }
};
