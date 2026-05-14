class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxes;

        for(int i=0; i<n-k+1; i++) {
            int currMax = nums[i];
            for(int j=i; j<i+k; j++) {
                currMax = max(currMax,nums[j]);
            }
            maxes.push_back(currMax);
        }

        return maxes;
    }
};
