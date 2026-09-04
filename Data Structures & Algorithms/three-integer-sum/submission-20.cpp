class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> trips;
        unordered_map<int,int> count;
        for(int num : nums) {
            count[num]++;
        }

        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
            count[nums[i]]--;
            
            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }

            for(int j=i+1; j<n; j++) {
                count[nums[j]]--;

                if(j>i+1 && nums[j-1] == nums[j]) {
                    continue;
                }

                int comp = -(nums[i] + nums[j]);

                if(count[comp] > 0) {
                    trips.push_back({nums[i],nums[j],comp});
                }
            }

            for(int j=i+1; j<n; j++) {
                count[nums[j]]++;
            }
        }
        return trips;
    }
};
