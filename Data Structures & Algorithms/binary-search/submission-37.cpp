class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        // lower-bound : first index greater than or equal to target

        auto it = lower_bound(nums.begin(),nums.end(),target);

        return it != nums.end() && *it == target ? it-nums.begin() : -1;
    }
};
