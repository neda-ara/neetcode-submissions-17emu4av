class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        auto it = lower_bound(nums.begin(),nums.end(),target);

        return it != nums.end() &&  *it == target ? it-nums.begin() : -1;
    }
};
