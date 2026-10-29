class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        if(n == 0) {
            return 0;
        }

        vector<int> left(n,height[0]);
        vector<int> right(n,height[n-1]);

        for(int i=1; i<n; i++) {
            left[i] = max(height[i],left[i-1]);
            right[n-i-1] = max(height[n-i-1],right[n-i]);
        }

        for(int i=0; i<n; i++) {
            water += min(left[i],right[i]) - height[i];
        }

        return water;
    }
};
