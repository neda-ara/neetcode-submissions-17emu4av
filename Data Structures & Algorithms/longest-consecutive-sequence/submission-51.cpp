class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int n = nums.size(), len = 0;
        int i = 0, curr = nums[0], streak = 0;

        while (i < n) {
            if (curr != nums[i]) {
                streak = 0;
                curr = nums[i];
            }
            while (i < n && curr == nums[i]) {
                i++;
            }
            streak++;
            curr++;
            len = max(len, streak);
        }

        return len;
    }
};
