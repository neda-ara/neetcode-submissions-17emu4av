class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n-1, max_water = 0;

        while(l < r) {
            max_water = max(max_water,min(heights[r],heights[l])*(r-l));
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_water;
    }
};
