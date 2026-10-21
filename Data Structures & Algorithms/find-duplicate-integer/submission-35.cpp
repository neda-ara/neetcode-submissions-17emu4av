class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int abs_num = abs(nums[i]);
            if (nums[abs_num] < 0) {
                return abs_num;
            }
            nums[abs_num] *= -1;
        }

        return -1;
    }
};
