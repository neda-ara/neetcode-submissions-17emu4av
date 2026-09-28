class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // every bar is part of the largest possible reactangle spanning over adjacent bars with height more than or equal to this bar

        //calculate this max possible area at every bar and keep track of max area found so far

        // use a stack to calculate the immediate smaller bar on left and right side for every bar so we dont re-compute this for every bar in a nested loop

        int n = heights.size(), area_max = 0;

        vector<int> left_smaller(n,-1);
        vector<int> right_smaller(n,n);

        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left_smaller[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while(stk.size()) {
            stk.pop();
        }

        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right_smaller[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        for(int i=0; i<n; i++) {
            int left = left_smaller[i], right = right_smaller[i];

            int area = heights[i] * (right-left-1);
            area_max = max(area_max,area);
        }
        return area_max;
    }
};
