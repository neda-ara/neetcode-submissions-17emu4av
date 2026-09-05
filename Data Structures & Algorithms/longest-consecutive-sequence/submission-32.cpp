class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) {
            return n;
        }

        sort(nums.begin(),nums.end());

        int i = 0, curr = nums[0], streak = 0, len = 0;

        while(i < n) {
            if(nums[i] != curr) {
                curr = nums[i];
                streak = 0;
            }
            while(i<n && nums[i] == curr) {
                i++;
            }
            curr++;
            streak++;
            len = max(len,streak);
        }

        return len;
    }
};
