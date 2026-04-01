class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int currSum = 0;

            for(int j=i; j<n; j++) {
                currSum += nums[j];
                if(currSum == k) {
                    total++;
                }
            }
        }

        return total;
    }
};