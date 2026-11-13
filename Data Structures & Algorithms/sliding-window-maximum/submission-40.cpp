class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> window_max(n - k + 1);

        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < n; i++) {
            while(!maxHeap.empty() && maxHeap.top().second <= i-k) {
                maxHeap.pop();
            }
            maxHeap.push({nums[i],i});

            if(i >= k-1) {
                window_max[i-k+1] = maxHeap.top().first;
            }
        }
        return window_max;
    }
};
