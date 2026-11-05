class Solution {
   public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> arr1 = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> arr2 = vector<int>(nums.begin() + 1, nums.end());

        return max(houseRobberLinear(arr1), houseRobberLinear(arr2));
    }

    int houseRobberLinear(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int robPrev = 0, robPrevPrev = 0;

        for (int i = 0; i < n; i++) {
            int currPrev = max(robPrev, nums[i] + robPrevPrev);
            robPrevPrev = robPrev;
            robPrev = currPrev;
        }

        return robPrev;
    }
};