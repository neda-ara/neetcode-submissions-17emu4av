class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        if (n == 0) {
            return 0;
        }

        int l = 0, r = n - 1, lm = height[l], rm = height[r];

        while (l < r) {
            if (lm <= rm) {
                l++;
                lm = max(lm, height[l]);
                water += lm - height[l];
            } else {
                r--;
                rm = max(rm, height[r]);
                water += rm - height[r];
            }
        }

        return water;
    }
};
