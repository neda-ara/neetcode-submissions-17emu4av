class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l=0, r=n-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        int res = bs(nums,target,0,l-1);
        if(res != -1) {
            return res;
        }

        return bs(nums,target,l,n-1);
    }

    int bs(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};
