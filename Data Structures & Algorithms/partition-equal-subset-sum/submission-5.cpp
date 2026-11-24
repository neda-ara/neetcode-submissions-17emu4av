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
        unordered_set<int> dp;
        dp.insert(0);

        for (int i = 0; i < nums.size(); i++) {
            unordered_set<int> nextDp;

            for (int t : dp) {
                if (t + nums[i] == target) {
                    return true;
                }
                nextDp.insert(t + nums[i]);
                nextDp.insert(t);
            }
            swap(dp, nextDp);
        }

        return false;
    }
};
