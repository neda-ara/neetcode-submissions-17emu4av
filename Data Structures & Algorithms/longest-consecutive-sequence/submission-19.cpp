class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(),nums.end());

        int max_streak = 0, streak = 0, curr = nums[0]; 
        int n = nums.size(), i = 0;

        while(i < n) {
            if(curr != nums[i]) {
                curr = nums[i];
                streak = 0;
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
