class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;

        sort(nums.begin(),nums.end());

        unordered_map<int,int> cnt;
        for(int num : nums) {
            cnt[num]++;
        }
        
        int n = nums.size();
        for(int i=0; i<n; i++) {
            cnt[nums[i]]--;

            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }

            for(int j=i+1; j<n; j++) {
                cnt[nums[j]]--;
                if(j > i+1 && nums[j-1] == nums[j]) {
                    continue;
                }

                int target = -(nums[i]+nums[j]);
                if(cnt[target] > 0) {
                    triplets.push_back({nums[i],nums[j],target});
                }
            }

            for(int j=i+1; j<n; j++) {
                cnt[nums[j]]++;
            }
        }
        return triplets;
    }
};
