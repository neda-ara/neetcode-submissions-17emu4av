class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;
        priority_queue<pair<int,int>> heap;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            heap.push({nums[i],i});
            
            if(i >= k-1) {
                while(!heap.empty() && heap.top().second <= i-k) {
                    heap.pop();
                }
                window_max.push_back(heap.top().first);
            }
         }

        return window_max;
    }
};
