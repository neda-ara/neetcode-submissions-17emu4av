class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;
        int l = 0, r = n - 1, lm = height[0], rm = height[n-1];

        while(l < r) {
            lm = max(height[l],lm);
            rm = max(rm,height[r]);
            if(lm < rm) {
                water += lm - height[l];
                l++;
            } else {
                water += rm - height[r];
                r--;
            }
        }

        return water;
    }
};
