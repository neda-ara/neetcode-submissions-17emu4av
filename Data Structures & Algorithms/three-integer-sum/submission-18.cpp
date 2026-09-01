class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        vector<vector<int>> triplets;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                break;
            }
            if(i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            int l = i+1, r = n-1;
            while(l < r) {
                int curr_sum = nums[i] + nums[l] + nums[r];
                if(curr_sum == 0) {
                    triplets.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l-1] == nums[l]) {
                        l++;
                    }
                } else if (curr_sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return triplets;
    }
};
