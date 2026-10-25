class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        auto it = upper_bound(nums.begin(),nums.end(),target);

        return it != nums.begin() &&  *prev(it) == target ? it-nums.begin()-1 : -1;
    }
};
