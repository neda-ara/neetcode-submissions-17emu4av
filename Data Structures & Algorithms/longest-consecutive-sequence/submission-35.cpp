class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniques(nums.begin(),nums.end());

        int n = nums.size(), max_len = 0;

        for(int num : nums) {
            if(!uniques.count(num-1)) {
                int streak = 1;
                while(uniques.count(num+streak)) {
                streak++;
            }
            max_len = max(max_len,streak);
            }
        }

        return max_len;
    }
};
