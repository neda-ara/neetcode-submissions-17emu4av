class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> leftMax(n,nums[0]);
        vector<int> rightMax(n,nums[n-1]);

        for(int i=1; i<n; i++) {
            if(i % k == 0) {
                leftMax[i] = nums[i];
            } else {
                leftMax[i] = max(leftMax[i-1],nums[i]);
            }

            if((n-i-1) % k == 0) {
                rightMax[n-i-1] = nums[n-i-1];
            } else {
                rightMax[n-i-1] = max(rightMax[n-i],nums[n-i-1]);
            }
        }

        vector<int> window_max;
        for(int i=0; i<n-k+1; i++) {
            window_max.push_back(max(leftMax[i+k-1],rightMax[i]));
        }

        return window_max;
    }
};
