class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        auto it = upper_bound(nums.begin(),nums.end(),target);
        
        if(it == nums.begin()) {
            return -1;
        }
        --it;
        return *it == target ? it - nums.begin() : -1;
    }
};
