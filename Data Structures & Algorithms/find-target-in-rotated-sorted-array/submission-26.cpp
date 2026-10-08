class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int pivot_idx = l;
        l = 0, r = n - 1;

        if (target >= nums[pivot_idx] && target <= nums[n - 1]) {
            l = pivot_idx;
        } else {
            r = pivot_idx - 1;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target) {
                return m;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return -1;
    }
};
