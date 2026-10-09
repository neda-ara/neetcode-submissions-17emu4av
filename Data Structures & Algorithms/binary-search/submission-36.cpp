class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        // lower-bound : first index greater than or equal to target

        while (l < r) {
            int mid = l + (r - l) / 2;

            if(nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l < nums.size() && nums[l] == target ? l : -1;
    }
};
