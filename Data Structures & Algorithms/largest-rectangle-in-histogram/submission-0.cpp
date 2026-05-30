class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, n = heights.size();

        for(int i=0; i<n; i++) {
            int curr = heights[i];

            int j = i-1;
            while(j>=0 && heights[j] >= heights[i]) {
                curr += heights[i];
                j--;
            }

            j=i+1;
            while(j<n && heights[j] >= heights[i]) {
                curr += heights[i];
                j++;
            }

            area = max(area,curr); 
        }
        return area;
    }
};
