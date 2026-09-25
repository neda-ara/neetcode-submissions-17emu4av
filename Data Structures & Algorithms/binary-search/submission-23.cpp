class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        auto it = lower_bound(nums.begin(),nums.end(),target);
        
        if(it == nums.end()) {
            return -1;
        }
        
        return *it == target ? it - nums.begin() : -1;
    }
};
