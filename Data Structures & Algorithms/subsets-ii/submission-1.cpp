class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack({},0,nums);
        return res;
    }

    void backtrack(vector<int> subset, int i, vector<int>& nums) {
        if(i == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(subset,i+1,nums);
        subset.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        backtrack(subset,i+1,nums);
    }
};
