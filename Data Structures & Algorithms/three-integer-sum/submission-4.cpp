class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        unordered_map<int,int> count;
        for(int num : nums) {
            count[num]++;
        }

        int n = nums.size();
        vector<vector<int>>triplets;
        for(int i=0; i<n; i++) {
            count[nums[i]]--;
            if(i>0 && nums[i] == nums[i-1]) continue;

            for(int j=i+1; j<n; j++) {
                count[nums[j]]--; 
                if(j>i+1 && nums[j] == nums[j-1]) continue;

                int thirdNum = -(nums[i] + nums[j]);
                if(count[thirdNum]>0){
                    triplets.push_back({nums[i],nums[j],thirdNum});
                }
            }

            for(int j=i+1; j<n; j++) {
                count[nums[j]]++;
            }
        }
        return triplets;
    }
};
