class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> output;
        deque<int> dq;

        int l = 0;
        for(int r=0; r<n; r++) {
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(l > dq.front()) {
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
