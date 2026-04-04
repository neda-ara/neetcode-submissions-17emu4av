class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), area = 0;
        int l = 0, r = n -1;

        while(l < r) {
            int height = min(heights[l], heights[r]);
            int width = r - l;
            int currArea = height * width;

            if(currArea > area) {
                area = currArea;
            }

            if(heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return area;   
    }
};
