class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int> idx;
        for(int i=0; i<n; i++) {
            int comp = target - nums[i];

            if(idx.count(comp)) {
                return {idx[comp],i};
            }
            idx[nums[i]] = i;
        }

        return {};
    }
};
