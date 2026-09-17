class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = upper_bound(nums.begin(),nums.end(),target);
        
        return (it != nums.begin() && *(it-1) == target) ? it - nums.begin() - 1 : -1;
    }

    
};
