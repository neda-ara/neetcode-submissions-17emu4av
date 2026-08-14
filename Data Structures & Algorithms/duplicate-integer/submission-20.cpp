class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uniques(nums.begin(),nums.end());
        return uniques.size() < nums.size();
    }
};