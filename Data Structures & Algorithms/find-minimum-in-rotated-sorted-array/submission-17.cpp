class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.empty()) {
            return -1;
        }

        int n = nums.size(), min_g = nums[0];
        int l = 0, r = n-1;

        while(l <= r) {
            if(nums[l] <= nums[r]) {
                min_g = min(min_g,nums[l]);
            }
            int m = l + (r-l)/2;
            min_g = min(min_g,nums[m]);

            if(nums[l] <= nums[m]) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return min_g;
    }
};
