class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;

        int n = nums.size();

        priority_queue<pair<int,int>> maxHeap;

        for(int i=0; i<n; i++) {
            while(!maxHeap.empty() && maxHeap.top().second <= i-k) {
                maxHeap.pop();
            }
            maxHeap.push({nums[i],i});
            if(i >= k-1) {
                output.push_back(maxHeap.top().first);
            }
        }

        return output;
    }
};
