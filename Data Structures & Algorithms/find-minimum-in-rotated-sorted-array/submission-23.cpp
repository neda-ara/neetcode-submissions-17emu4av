class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1, res = INT_MAX;

        while(l <= r) {
            if(nums[l] <= nums[r]) {
                res = min(res,nums[l]);
            }
            int m = l + (r-l)/2;
            res = min(res,nums[m]);

            if(nums[l] <= nums[m]) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return res;
    }
};
