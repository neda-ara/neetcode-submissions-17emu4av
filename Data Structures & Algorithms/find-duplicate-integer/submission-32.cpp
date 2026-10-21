class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> seen;

        for(int i=0; i<n; i++) {
            if(seen.count(nums[i])) {
                return nums[i];
            }
            seen.insert(nums[i]);
        }

        return -1;
    }
};
