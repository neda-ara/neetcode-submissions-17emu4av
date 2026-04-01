class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> frequency;

        for(int i=0; i<nums.size(); i++) {
            if(frequency.find(nums[i]) != frequency.end()){
                return true;
            } else {
                frequency[nums[i]]++;
            }
        }

        return false;
    }
};