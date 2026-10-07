class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), mini = INT_MAX;
        int l = 0, r = n-1;

        while(l <= r) {
            if(nums[l] <= nums[r]) {
                return min(mini,nums[l]);
            }

            int m = l + (r-l)/2;
            mini = min(mini,nums[m]);

            if(nums[l] <= nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }

        }

        return mini;
    }
};
