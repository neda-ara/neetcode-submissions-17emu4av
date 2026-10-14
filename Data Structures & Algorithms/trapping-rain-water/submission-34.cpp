class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        vector<int> left(n,height[0]);
        vector<int> right(n,height[n-1]);

        for(int i=1; i<n; i++) {
            left[i] = max(left[i-1],height[i]);
            right[n-i-1] = max(right[n-i],height[n-i-1]);
        }

        for(int i=0; i<n; i++) {
            int curr = min(left[i],right[i]) - height[i];
            water += curr;
        }

        return water;
    }
};
