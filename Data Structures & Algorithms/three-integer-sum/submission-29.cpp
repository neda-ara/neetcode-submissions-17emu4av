class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> triplets;

        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
           if(nums[i] > 0) {
            break;
           }
           if(i>0 && nums[i-1] == nums[i]) {
            continue;
           }

           int l = i+1, r = n-1;
           while(l < r) {
            int curr = nums[i] + nums[l] + nums[r];

            if(curr == 0) {
                triplets.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while(l<n && nums[l-1] == nums[l]) {
                    l++;
                }
            } else if (curr > 0) {
                r--;
            } else {
                l++;
            }
           }
        }

        return triplets;
    }
};
