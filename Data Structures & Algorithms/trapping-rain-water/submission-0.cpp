class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), total = 0;

        for(int i=0; i<n; i++) {
            int leftMax = height[i], rightMax = height[i];

            for(int j=0; j<i; j++) {
                if(height[j] > leftMax) {
                    leftMax = height[j];
                }
            }
            for(int j=i+1; j<n; j++) {
                if(height[j] > rightMax) {
                    rightMax = height[j];
                }
            }
            total += min(leftMax,rightMax) - height[i];
        }

        return total;
    }
};
