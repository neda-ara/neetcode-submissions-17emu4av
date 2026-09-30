class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), total_prod = 1, zeroes = 0;

        vector<int> products(n);

        for(int num : nums) {
            if(num == 0) {
                zeroes++;
            } else {
                total_prod *= num;
            }
        }

        if(zeroes > 1) {
            return vector<int>(n,0);
        }

        for(int i=0; i<n; i++) {
            if(zeroes > 0) {
                products[i] = nums[i] == 0 ? total_prod : 0;
            } else {
                products[i] = total_prod / nums[i];
            }
        }

        return products;
    }
};
