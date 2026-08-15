class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProd = 1, n = nums.size(), zeroes = 0;

        for(int num : nums) {
            if(num == 0) {
                zeroes++;
            } else {
                totalProd *= num;
            }
        }

        if(zeroes > 1) {
            return vector<int> (n,0);
        }

        vector<int> products(n,1);
        for(size_t i=0; i<n; i++) {
            if(zeroes == 1) {
                products[i] = nums[i] == 0 ? totalProd : 0; 
            } else {
                products[i] = totalProd / nums[i];
            }
        }
        return products;
    }
};
