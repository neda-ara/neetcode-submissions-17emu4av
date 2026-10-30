class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), z = 0, prod = 1;

        vector<int> products(n, 0);

        for (int num : nums) {
            if (num == 0) {
                z++;
            } else {
                prod *= num;
            }
        }

        if (z > 1) {
            return products;
        }

        for (int i = 0; i < n; i++) {
            if (z > 0) {
                products[i] = nums[i] == 0 ? prod : 0;
            } else {
                products[i] = prod / nums[i];
            }
        }

        return products;
    }
};
