class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) {
            return n;
        }

        int max_len = 0, curr = nums[0], streak = 0, i = 0;
        sort(nums.begin(),nums.end());

        while(i < n) {
            if(curr != nums[i]) {
                curr = nums[i];
                streak = 0;
            }
            while(i<n && curr == nums[i]) {
                i++;
            }
            curr++;
            streak++;
            max_len = max(max_len,streak);
        }

        return max_len;
    }
};
