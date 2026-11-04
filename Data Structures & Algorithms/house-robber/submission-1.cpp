class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return dfs(nums,0,memo);
    }

    int dfs(vector<int>& nums, int i, vector<int>& memo) {
        if(i >= nums.size()) {
            return 0;
        }
        if(memo[i] != -1) {
            return memo[i];
        }
        memo[i] = max(dfs(nums,i+1,memo),dfs(nums,i+2,memo)+nums[i]);
        return memo[i];
    }

    // two choices: rob this house and calculate for the one after next, 
    // skip this house and calculate for the next
};
