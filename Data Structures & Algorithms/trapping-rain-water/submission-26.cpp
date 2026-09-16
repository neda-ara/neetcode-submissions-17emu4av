class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        vector<int> left_max(n,height[0]);
        vector<int> right_max(n,height[n-1]);

        for(int i=1; i<n; i++) {
            left_max[i] = max(left_max[i-1],height[i]);
            right_max[n-i-1] = max(right_max[n-i],height[n-i-1]);
        }

        for(int i=0; i<n; i++) {
            water += min(left_max[i],right_max[i]) - height[i];
        }
        return water;
    }
};
