class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int num : nums) {
            int abs = num > 0 ? num : num * -1;
            int absIdx = abs - 1;

            if (nums[absIdx] < 0) {
                return abs;
            }
            nums[absIdx] *= -1;
        }

        return -1;
    }
};
