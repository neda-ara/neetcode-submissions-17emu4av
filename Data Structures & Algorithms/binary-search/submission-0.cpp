class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r) {
            int mid = (r-l)/2 + l;

            if(target > nums[mid]) {
                l = mid+1;
            } else if (target < nums[mid]) {
                r = mid-1;
            } else if (target == nums[mid]) {
                return mid;
            }
        }
        return -1;
    }
};
