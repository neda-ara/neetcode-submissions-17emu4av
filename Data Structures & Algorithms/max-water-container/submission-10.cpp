class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), water = 0;
        int l=0, r = n-1;

        while(l < r) {
            int curr = min(heights[l],heights[r]) * (r-l);
            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
            water = max(water,curr);
        }
        return water;
    }
};
