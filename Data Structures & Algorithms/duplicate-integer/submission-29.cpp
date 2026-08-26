class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uniques;

        for(int num : nums) {
            if(uniques.count(num)) {
                return true;
            }
            uniques.insert(num);
        }
        return false;
    }
};