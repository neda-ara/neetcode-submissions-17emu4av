class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.begin(),nums.end()).size();
    }
};