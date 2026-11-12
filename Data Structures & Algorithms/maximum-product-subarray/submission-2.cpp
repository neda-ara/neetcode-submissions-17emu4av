class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int res = nums[0], currMin = 1, currMax = 1;

        for (int num : nums) {
            int oldMax = currMax, oldMin = currMin;

            currMax = max({num, num * oldMax, num * oldMin});
            currMin = min({num, num * oldMax, num * oldMin});
            res = max(res, currMax);
        }

        return res;
    }
};
