class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l < r) {
            int m = l + (r-l)/2;

            if(nums[m] <= nums[r]) {
                r = m;
            } else {
                l = m+1;
            }
        }

        int pivotIdx = l;
        int pivotEl = nums[pivotIdx];
        l = 0, r = n-1;

        if(target == pivotEl) {
            return pivotIdx;
        } else if(target > pivotEl && target <= nums[n-1]) {
            l = pivotIdx + 1;
        } else {
            r = pivotIdx - 1;
        }

        while(l <= r) {
            int m  = l + (r-l)/2;

            if(nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return -1;
    }
};
