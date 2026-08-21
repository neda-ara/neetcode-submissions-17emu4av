class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i = 0, streak = 0, curr = nums[0], maxStreak = 0;

        while(i < nums.size()) {
            if(nums[i] != curr) {
                streak = 0;
                curr = nums[i];
            } 
            while(i < nums.size() && nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            maxStreak = max(maxStreak,streak);
        }
        return maxStreak;
    }
};
