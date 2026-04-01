class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0, currSum = 0;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;

        for(int num : nums) {
            currSum += num;
            total += prefixSum[currSum - k];
            prefixSum[currSum]++;
        }

        return total;
    }
};