class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        while(l < r) {
            int m = (r-l)/2 + l;
            if(nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        if(target >= nums[pivot] && target <= nums[n-1]) {
            l = pivot;
            r = n - 1;
        } else {
            l = 0;
            r = pivot - 1;
        }

        while(l <= r) {
            int m = (r-l)/2 + l;
            if(nums[m] == target) {
                return m;
            } else if(nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
