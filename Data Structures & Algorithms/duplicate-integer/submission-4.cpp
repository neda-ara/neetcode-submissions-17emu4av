class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> frequency;

        for(int num : nums) {
            if(frequency.count(num) > 0) {
                return true;
            }
            frequency[num]++;
        }

        return false;
    }
};