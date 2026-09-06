class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(nums,{},0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int> subset, int i) {
        res.push_back(subset);

        for(int j=i; j<nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) {
                continue;
            }
            subset.push_back(nums[j]);
            backtrack(nums,subset,j+1);
            subset.pop_back();
        }
    }
};
