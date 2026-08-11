class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uniques;

        for(int i=0; i<nums.size(); i++) {
            uniques.insert(nums[i]);
        }

        return uniques.size() != nums.size();
    }
};