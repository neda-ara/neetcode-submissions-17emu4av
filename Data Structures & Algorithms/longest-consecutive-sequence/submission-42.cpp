class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        //unordered_set<int> all(nums.begin(), nums.end());

        if(nums.empty()) {
            return 0;
        }

        sort(nums.begin(),nums.end());

        int n = nums.size(), max_streak = 0;
        int curr = nums[0], curr_streak = 0, i = 0;

        while (i < n) {
            if(nums[i] != curr) {
                curr = nums[i];
                curr_streak = 0;
            }
            while(i < n && nums[i] == curr) {
                i++;
            }
            curr_streak++;
            curr++;

            max_streak = max(max_streak,curr_streak);
        }

        return max_streak;
    }
};
