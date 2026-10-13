class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int num : nums) {
            int abs_num = num > 0 ? num : num * -1;

            if(nums[abs_num-1] < 0) {
                return abs_num;
            }
            nums[abs_num-1] *= -1;
        }

        return -1;
    }
};
