class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;

        int n = nums.size(), l=0;
        if(n == 0) {
            return {};
        }

        deque<int> dq;

        for(int r=0; r<n; r++) {
            while(!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(dq.front() < l) {
                dq.pop_front();
            }
            if(r >= k-1) {
                output.push_back(nums[dq.front()]);
                l++;
            }
        }

        return output;
    }
};
