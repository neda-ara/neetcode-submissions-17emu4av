class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num : nums) {
            int currIdx  = abs(num) - 1;

            if(nums[currIdx] < 0) {
                return abs(num);
            }

            nums[currIdx] *= -1;
        }

        return -1;
    }
};
