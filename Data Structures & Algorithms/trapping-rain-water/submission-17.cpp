class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        vector<int> leftmax(n);
        vector<int> rightmax(n);

        for(int i=1; i<n; i++) {
            leftmax[i] = max(leftmax[i-1],height[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
            rightmax[i] = max(rightmax[i+1],height[i+1]);
        }

        for(int i=0; i<n; i++) {
            int lm = max(height[i],leftmax[i]);
            int rm = max(height[i],rightmax[i]);

            water += min(lm,rm) - height[i];
        }
        return water;
    }
};
