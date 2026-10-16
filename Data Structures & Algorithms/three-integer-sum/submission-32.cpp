class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;

        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i+1, r = n-1;

            while(l < r) {
                int currSum = nums[i] + nums[l] + nums[r];

                if(currSum == 0) {
                    triplets.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;

                    while(l<n && nums[l] == nums[l-1]) {
                        l++;
                    }
                } else if(currSum > 0) {
                    r--;
                } else {
                    l++;
                }
            }   
        }

        return triplets;
    }
};
