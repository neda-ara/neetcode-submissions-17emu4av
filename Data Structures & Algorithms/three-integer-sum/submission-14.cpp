class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<vector<int>> triplets;

        for(int i=0; i<n; i++) {
            int target = -nums[i];
            int l=i+1, r=n-1;

            if(nums[i] > 0) {
                break;
            } 
            if(i > 0 && nums[i-1] == nums[i]) {
                continue;
            }

            while(l < r) {
                int currSum = nums[l] + nums[r];
                if(currSum == target) {
                    triplets.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l-1] == nums[l]) {
                        l++;
                    }
                } else if(currSum > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return triplets;
    }
};
