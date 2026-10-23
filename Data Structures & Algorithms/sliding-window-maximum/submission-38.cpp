class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) {
            return {};
        }

        vector<int> output(n-k+1,0);

        deque<int> dq;
        int l = 0;

        for(int r=0; r<n; r++) {
            while(!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(dq.front() < l) {
                dq.pop_front();
            }

            if(r >= k-1) {
                output[r-k+1] = nums[dq.front()];
                l++;
            }
        }

        return output;
    }
};
