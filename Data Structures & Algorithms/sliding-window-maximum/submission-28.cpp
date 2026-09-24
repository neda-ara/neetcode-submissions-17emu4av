class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;

        int n = nums.size();

        deque<int> dq;

         int l = 0, i = 0;
         while(i < n) {
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(dq.front() < l) {
                dq.pop_front();
            }
            if(i >= k-1) {
                window_max.push_back({nums[dq.front()]});
                l++;
            }
            i++;
         } 

        return window_max;
    }
};
