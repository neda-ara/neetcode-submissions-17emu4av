class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        vector<bool> nextDp(target + 1, false);

        dp[0] = true;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    nextDp[j] = dp[j] || dp[j - nums[i]];
                } else {
                    nextDp[j] = dp[j];
                }
            }
            swap(nextDp, dp);
        }

        return dp[target];
    }
};
