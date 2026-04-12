class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique;

        for(int num : nums) {
            unique.insert(num);
        }

        return unique.size() != nums.size();
    }
};