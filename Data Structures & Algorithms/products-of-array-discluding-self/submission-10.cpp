class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), z = 0, tp = 1;

        for(int num : nums) {
            if(num == 0) {
                z++;
            } else {
                tp *= num;
            }
        }

        if(z > 1) {
            return vector<int> (n,0);
        }

        vector<int> products(n);
        for(int i=0; i<n; i++) {
            if(z == 1) {
                products[i] = nums[i] == 0 ? tp : 0;
            } else {
                products[i] = tp/nums[i];
            }
        }

        return products;
    }
};
