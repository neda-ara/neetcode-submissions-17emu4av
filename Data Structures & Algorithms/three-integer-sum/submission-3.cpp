class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        set<vector<int>> triplets;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[i] +nums[j]+nums[k] == 0) {
                        triplets.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(triplets.begin(),triplets.end());
    }
};
