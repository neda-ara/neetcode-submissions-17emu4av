class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0];

        for(int i=0; i<n; i++) {
            int currSum = 0;
            for(int j=i; j<n; j++) {
                currSum += nums[j];
                maxSum = max(currSum, maxSum);   
            }
        }
        return maxSum;
    }
};
