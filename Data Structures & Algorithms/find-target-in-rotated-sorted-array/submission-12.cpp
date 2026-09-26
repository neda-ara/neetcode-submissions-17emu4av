class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;

        while(l < r) {
            int mid = (r-l)/2 + l;
            if(nums[mid] <= nums[r]) {
                r = mid;
            } else { 
                l = mid + 1;
            }
        }

        int pivot = l;
        int res = bs(nums,target,0,pivot-1);
        if(res != -1) {
            return res;
        } else {
            return bs(nums,target,pivot,n-1);
        }

        return -1;
    }

    int bs(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
