class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxes(n-k+1);
        deque<int> deq;
        int l = 0, r = 0;

        while(r < n) {
            while(!deq.empty() && nums[deq.back()] < nums[r]) {
                deq.pop_back();
            }
            deq.push_back(r);

            if(l > deq.front()) {
                deq.pop_front();
            }

            if((r+1) >= k) {
                maxes[l] = nums[deq.front()];
                l++;
            }
            r++; 
        }
        return maxes;
    }
};
