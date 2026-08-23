class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxSoFar = 0, l = 0, r = heights.size() - 1;

        while(l < r) {
            int height = min(heights[l],heights[r]);
            int width = r-l;
            maxSoFar = max(maxSoFar, height*width);

            if(heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxSoFar;
    }
};
