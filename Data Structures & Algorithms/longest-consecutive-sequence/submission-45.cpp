class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;

        unordered_set<int> all(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (!all.count(nums[i] - 1)) {
                int streak = 1;
                while (all.count(nums[i] + streak)) {
                    streak++;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};
