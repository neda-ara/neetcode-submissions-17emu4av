class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        priority_queue<pair<int,int>> maxHeap;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            maxHeap.push({nums[i],i});

            if(i >= k-1) {
                while(maxHeap.top().second <= i-k) {
                    maxHeap.pop();
                }
                output.push_back(maxHeap.top().first);
            }
        }

        return output;
    }
};
