class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> all(nums.begin(), nums.end());

        int n = nums.size(), len = 0;

        for (int i = 0; i < n; i++) {
            if (!all.count(nums[i] - 1)) {
                int streak = 1;
                while (all.count(nums[i] + streak)) {
                    streak++;
                }
                len = max(len, streak);
            }
        }

        return len;
    }
};
