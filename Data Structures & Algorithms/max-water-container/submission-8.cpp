class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), max_water = 0;
        int l = 0, r = n-1;

        while(l < r) {
            max_water = max(max_water,min(heights[l],heights[r])*(r-l));
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_water;
    }
};
