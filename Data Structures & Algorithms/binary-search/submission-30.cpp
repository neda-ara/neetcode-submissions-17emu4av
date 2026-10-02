class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        // lower-bound = first element greater than or equal to
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it != nums.end() && nums[it - nums.begin()] == target ? it - nums.begin() : -1;
    }
};
