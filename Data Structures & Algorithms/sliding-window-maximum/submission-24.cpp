class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;
        deque<int> dq;

        int n = nums.size(), l = 0;

        for(int r=0; r<n; r++) {
            while(dq.size() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(l > dq.front()) {
                dq.pop_front();
            }

            if(r >= k-1) {
                window_max.push_back(nums[dq.front()]);
                l++;
            }
        }

        return window_max;
    }
};
