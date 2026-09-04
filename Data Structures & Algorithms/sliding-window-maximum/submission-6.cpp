class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), l = 0;

        vector<int> output(n-k+1);
        deque<int> dq;

        for(int r=0; r<n; r++) {
            while(!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            if(l > dq.front()) {
                dq.pop_front();
            }

            if(r+1 >= k) {
                output[l] = nums[dq.front()];
                l++;
            }
        }
        return output;
    }
};
