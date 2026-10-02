class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        // lower-bound = first element greater than or equal to
        auto it = upper_bound(nums.begin(), nums.end(), target);
        return it != nums.begin() && nums[it - nums.begin() - 1] == target ? it - nums.begin() - 1
                                                                           : -1;
    }
};
