class Solution {
   public:
    vector<int> memo;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);

        int maxLIS = 1;
        for (int i = 0; i < n; i++) {
            maxLIS = max(maxLIS, dfs(i, nums));
        }
        return maxLIS;
    }

    int dfs(int i, vector<int>& nums) {
        if(memo[i] != -1) {
            return memo[i];
        }

        int LIS = 1;
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] < nums[j]) {
                LIS = max(LIS, 1 + dfs(j, nums));
            }
        }

        return memo[i] = LIS;
    }
};
