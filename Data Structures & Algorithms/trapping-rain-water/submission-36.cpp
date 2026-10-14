class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        int l = 0, r = n-1;
        int lm = height[0], rm = height[n-1];

        while(l <= r) {
            if(lm < rm) {
                lm = max(lm,height[l]);
                water += lm - height[l];
                l++;
            } else {
                rm = max(rm,height[r]);
                water += rm - height[r];
                r--;
            }
        }

        return water;
    }
};
