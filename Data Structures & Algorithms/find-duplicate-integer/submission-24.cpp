class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> all;
        int n = nums.size();

        for(int num : nums) {
            if(all.count(num)) {
                return num;
            }
            all.insert(num);
        }

        return -1;
    }
};
