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

        int res = bs(nums,target,0,l-1);
        if(res != -1) {
            return res;
        }

        return bs(nums,target,l,n-1);
    }

    int bs(vector<int>& nums, int target, int l, int r) {
        while(l <= r) {
            int m = l + (r-l)/2;

            if(nums[m] == target) {
                return m;
            } else if(nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return -1;
    }
};
