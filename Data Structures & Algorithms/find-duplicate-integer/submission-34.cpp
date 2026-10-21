class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int abs_num = abs(nums[i])-1;
            if (nums[abs_num] < 0) {
                return abs(nums[i]);
            }
            nums[abs_num] *= -1;
        }

        return -1;
    }
};
