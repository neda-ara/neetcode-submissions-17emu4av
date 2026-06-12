class Solution {
public:
    int findMin(vector<int> &nums) {
        /*A rotated sorted array contains exactly one discontinuity (rotation point). 
        Therefore, when split at any midpoint, at least one side must be completely 
        sorted.*/

        int res = nums[0];
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if(nums[l] < nums[r]) {
                res = min(res,nums[l]);
                break;
            }
            int m = (r-l)/2 + l;
            res = min(res,nums[m]);

            if(nums[m] >= nums[l]) {
                l = m+1;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};
