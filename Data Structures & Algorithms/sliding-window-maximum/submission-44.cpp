class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;
        if (n == 0) {
            return {};
        }

        vector<int> window_max(n - k + 1);

        deque<int> dq;

        for (int r = 0; r < n; r++) {
            while (!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            };
            dq.push_back(r);

            if (dq.front() < l) {
                dq.pop_front();
            }

            if (r >= k - 1) {
                window_max[r - k + 1] = nums[dq.front()];
                l++;
            }
        }

        return window_max;
    }
};
