class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return unordered_set(nums.begin(),nums.end()).size() != nums.size();
    }
};