class Solution {
public:
    int maxArea(vector<int>& heights) {
        int most_water = 0, n = heights.size();
        int l = 0, r = n-1;

        while(l < r) {
            int height = min(heights[l],heights[r]);
            int width = r-l;
            most_water = max(most_water,height*width);

            if(heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }

        }

        return most_water;
    }
};
