class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        while (l < r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l > 0 && nums[l-1] == target ? l - 1 : -1;
    }
};
