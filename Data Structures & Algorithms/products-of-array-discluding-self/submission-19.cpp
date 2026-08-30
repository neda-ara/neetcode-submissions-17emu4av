class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), total_product = 1, zeroes = 0;

        vector<int> products(n,0);

        for(int num : nums) {
            if(num == 0) {
                zeroes++;
            } else {
                total_product *= num;
            }
        }

        if(zeroes > 1) {
            return products;
        }

        for(int i=0; i<n; i++) {
            if(zeroes > 0) {
                products[i] = nums[i] == 0 ? total_product : 0;
            } else {
                products[i] = total_product / nums[i];
            }
        }

        return products;
    }
};
