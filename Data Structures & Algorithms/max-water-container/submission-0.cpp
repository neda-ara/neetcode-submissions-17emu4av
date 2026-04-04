class Solution {
public:
    int maxArea(vector<int>& heights) {
       int area = 0, n = heights.size();

       for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int height = min(heights[i], heights[j]);
            int width = j - i;
            if( height * width > area) {
                area = height * width;
            }
        }
       }
       return area; 
    }
};
