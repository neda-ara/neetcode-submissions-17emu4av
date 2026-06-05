class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l<=r) {
            int mid = (r-l)/2 + l;
            int midEl = nums[mid];

            if(midEl == target) {
                return mid;
            } else if (midEl > target) {
                r = mid - 1;
            } else if (midEl < target) {
                l = mid + 1;
            }
        }
        return -1;
    }
};
