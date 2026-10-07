class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> all(nums.begin(), nums.end());

        int n = nums.size(), max_streak = 0;

        for (int i = 0; i < n; i++) {
            int streak = 1;
            if (!all.count(nums[i] - 1)) {
                while (all.count(nums[i] + streak)) {
                    streak++;
                }
            }
            max_streak = max(max_streak, streak);
        }

        return max_streak;
    }
};
