class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> unq;

        for(int num : nums) {
            if(unq.count(num)) {
                return true;
            }
            unq.insert(num);
        }

        return false;
    }
};