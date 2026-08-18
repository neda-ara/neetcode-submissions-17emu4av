class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), i = 0, streak = 0, res = 0, curr = nums[0];

        if(n == 0) {
            return 0;
        }

        sort(nums.begin(),nums.end());

        while(i < n) {
            if(curr != nums[i]) {
                streak = 0;
                curr = nums[i];
            }
            while(i < nums.size() && nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            res = max(res,streak);
        }
        return res;
    }
};
