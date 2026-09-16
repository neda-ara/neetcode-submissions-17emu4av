class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> window_max;
        priority_queue<pair<int,int>> max_heap;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            max_heap.push({nums[i],i});
            if(i >= k-1) {
                while(!max_heap.empty() && max_heap.top().second < i-k+1) {
                    max_heap.pop();
                }
                window_max.push_back(max_heap.top().first);
            }
        }
        
        return window_max;
    }
};
