class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), water = 0, l = 0, r = n-1;

        while(l < r) {
            water = max(water,min(heights[l],heights[r])*(r-l));
            if(heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return water;
    }
};
