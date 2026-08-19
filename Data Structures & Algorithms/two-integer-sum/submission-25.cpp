class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> lookup;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            lookup[nums[i]] = i;
        }

        for(int i=0; i<n; i++) {
            int comp = target - nums[i];
            if(lookup.find(comp) != lookup.end() && i != lookup[comp]) {
                return {i,lookup[comp]};
            }
        }

        return {};
    }
};
