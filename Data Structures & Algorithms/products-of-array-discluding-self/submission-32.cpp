class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> products(n,1);

        int prod = 1, zeroes = 0;

        for(int num : nums) {
            if(num == 0) {
                zeroes++;
            } else {
               prod *= num; 
            }
        }

        if(zeroes > 1) {
            return vector<int> (n,0);
        }

        for(int i=0; i<n; i++) {
            int num = nums[i];
            if(zeroes > 0) {
                products[i] = num == 0 ? prod : 0;
            } else {
                products[i] = prod/num;
            }
        }

        return products;
    }
};
