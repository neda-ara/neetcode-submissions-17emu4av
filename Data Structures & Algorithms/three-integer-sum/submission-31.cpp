class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        unordered_map<int,int> count;

        for(int& num : nums) {
            count[num]++;
        }

        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
            count[nums[i]]--;
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for(int j=i+1; j<n; j++) {
                count[nums[j]]--;
                if(j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int target = -(nums[i] + nums[j]);
                if(count[target] > 0) {
                    triplets.push_back({nums[i],nums[j],target});
                }
            }
            for(int j=i+1; j<n; j++) {
                count[nums[j]]++;
            }
        }

        return triplets;
    }
};
