class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] <= nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        int pivot = l;
        int res = binary_search(nums,target,pivot,n-1);

        if(res != -1) {
            return res;
        }

        return binary_search(nums,target,0,pivot-1);
    }

    int binary_search(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int m = l + (r-l)/2;

            if(nums[m] == target) {
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
