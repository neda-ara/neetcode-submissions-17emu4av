class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), res = INT_MAX;

        int l = 0, r = n-1;

        while(l<=r) {
            if(nums[l] <= nums[r]) {
                res = min(res,nums[l]);
                break;
            }

            int m = l + (r-l)/2;
            res = min(res,nums[m]);

            if(nums[l] <= nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return res;
    }
};
