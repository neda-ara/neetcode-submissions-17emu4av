class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> result (2, 0);

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(hash.find(complement) != hash.end()) {
                result[0] = hash[complement];
                result[1] = i;
            }
            hash[nums[i]] = i;
        }

        return result;
    }
};
