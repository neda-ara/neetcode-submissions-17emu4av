class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        int totalArrProduct = 1, zeroCount = 0;

        for (int num : nums) {
            if(num != 0) {
                totalArrProduct *= num;
            } else {
                zeroCount++;
            }
        }

        if(zeroCount > 1) {
            return vector<int>(n,0);
        }
        
        vector<int> prod(n);
        for(size_t i=0; i<n; i++) {
            if(zeroCount > 0) {
                prod[i] = nums[i] == 0 ? totalArrProduct : 0;
            } else {
                prod[i] = totalArrProduct / nums[i];
            }
        }

        return prod;
    }
};
