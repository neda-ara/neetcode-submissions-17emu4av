class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (r-l)/2 + l;
            if(nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        int pivot = l;
        
        int res = binarySearch(nums,0,pivot-1,target);
        if(res != -1) {
            return res;
        }
        return binarySearch(nums,pivot,nums.size()-1,target);
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
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
