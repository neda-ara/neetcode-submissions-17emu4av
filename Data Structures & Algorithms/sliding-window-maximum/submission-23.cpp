class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;

        int n = nums.size();

        vector<int> left_max(n,nums[0]);
        vector<int> right_max(n,nums[n-1]);

        for(int i=1 ;i<n; i++) {
            if(i % k == 0) {
                left_max[i] = nums[i];
            } else {
                left_max[i] = max(left_max[i-1],nums[i]);
            }
            if((n-1-i) % k == 0) {
                right_max[n-i-1] = nums[n-i-1];
            } else {
                right_max[n-i-1] = max(right_max[n-i], nums[n-i-1]);
            }
        }

        for(int i=k-1; i<n; i++) {
            window_max.push_back(
                max(left_max[i],right_max[i-k+1])
            );
        }
        
        return window_max;
    }
};
