class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> arr1 = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> arr2 = vector<int>(nums.begin() + 1, nums.end());

        return max(houseRobberLinear(arr1), houseRobberLinear(arr2));
    }

    int houseRobberLinear(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp.back();
    }
};