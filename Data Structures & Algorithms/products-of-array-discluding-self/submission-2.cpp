class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> prod(n,1);

        for(size_t i=1; i<n; i++) {
            prod[i] = prod[i-1] * nums[i-1]; 
        }

        int postfix = 1;

        for(int i=n-1; i>=0; i--) {
            prod[i] *= postfix;
            postfix *= nums[i];
        }

        return prod;
    }
};
