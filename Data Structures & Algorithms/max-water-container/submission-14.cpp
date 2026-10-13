class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;

        int l=0, r=n-1;

        while(l < r) {
            if(heights[l] <= heights[r]) {
                max_area = max(max_area,(r-l)*heights[l]);
                l++;
            } else {
                max_area = max(max_area,(r-l)*heights[r]);
                r--;
            }
        }
        
        return max_area;
    }
};
