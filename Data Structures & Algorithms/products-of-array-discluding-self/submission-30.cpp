class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), total_prod = 1, zeroes = 0;

        vector<int> products(n,1);

        int prefix = 1, postfix = 1;

        for(int i=0; i<n; i++) {
            products[i] *= prefix;
            prefix *= nums[i];

            products[n-i-1] *= postfix;
            postfix *= nums[n-i-1];
        }

        return products;
    }
};
