class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size(), max_streak = 0;
        int i = 0, streak = 0, curr = nums[0];

        while(i < n) {
            if(curr != nums[i]) {
                streak = 0;
                curr = nums[i];
            }
            while(i<n && nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            max_streak = max(max_streak,streak);
        }

        return max_streak;
    }
};
