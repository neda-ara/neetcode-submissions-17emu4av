class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        if(n == 0) {
            return water;
        }

        int l = 0, r = n-1;
        int lm = height[l], rm = height[r];

        while(l < r) {
            if(lm <= rm) {
                water += lm - height[l];
                l++;
                lm = max(lm, height[l]);
            } else {
                water += rm - height[r];
                r--;
                rm = max(rm, height[r]);
            }
        }

        return water;
    }
};
