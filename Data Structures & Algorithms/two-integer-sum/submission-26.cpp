class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> lookup;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int comp = target - nums[i];
            if(lookup.find(comp) != lookup.end()) {
                return {lookup[comp],i};
            }
            lookup.insert({nums[i],i});
        }

        return {};
    }
};
