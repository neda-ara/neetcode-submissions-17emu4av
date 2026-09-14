class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), totalP = 1, zeroes = 0;

        for(int num : nums) {
            if(num == 0) {
                zeroes++;
            } else {
                totalP *= num;
            }
        }

        if(zeroes > 1) {
            return vector<int>(n,0);
        }

        vector<int> res(n);
        for(int i=0; i<n; i++) {
            if(zeroes > 0) {
                res[i] = nums[i] == 0 ? totalP : 0;
            } else {
                res[i] = totalP / nums[i];
            }
        }

        return res;
    }
};
