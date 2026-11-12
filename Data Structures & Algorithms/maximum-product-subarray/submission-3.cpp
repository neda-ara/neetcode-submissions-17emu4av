class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size(), res = nums[0];
        int prefix = 0, suffix = 0;

        for (int i = 0; i < n; i++) {
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);
            suffix = nums[n - i - 1] * (suffix == 0 ? 1 : suffix);
            res = max({res, prefix, suffix});
        }

        return res;
    }
};
