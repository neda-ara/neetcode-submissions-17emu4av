class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, water = 0;
        int lm = height[l], rm = height[r];

        while(l < r) {
            if(lm < rm) {
                l++;
                lm = max(lm,height[l]);
                water += lm - height[l];
            } else {
                r--;
                rm = max(rm,height[r]);
                water += rm - height[r];
            }
        }
        return water;
    }
};
