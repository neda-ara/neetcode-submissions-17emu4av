class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        unordered_map<int,int> freq;
        vector<vector<int>> triplets;

        for(int num : nums) {
            freq[num]++;
        }

        for(int i=0; i<n; i++) {
            freq[nums[i]]--;
            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            for(int j=i+1; j<n; j++) {
                freq[nums[j]]--;
                if(j>i+1 && nums[j-1] == nums[j]) {
                    continue;
                }
                int target = -(nums[i] + nums[j]);

                if(freq[target] > 0) {
                    triplets.push_back({nums[i],nums[j],target});
                }
            }

            for(int j=i+1; j<n; j++) {
                freq[nums[j]]++;
            }
        }
        return triplets;
    }
};
