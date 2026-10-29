class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int num : nums) {
            int abs_num = abs(num);

            if(nums[abs_num] < 0) {
                return abs_num;
            }

            nums[abs_num] *= -1;
        }

        return -1;
    }
};
