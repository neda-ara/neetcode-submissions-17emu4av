class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0];

        for(int i=0; i<n; i++) {
            int currSum = 0;

            for(int j=i; j<i+n; j++) {
                currSum += nums[j%n];
                maxSum = max(maxSum,currSum);
            }
        }
        return maxSum;
    }
};