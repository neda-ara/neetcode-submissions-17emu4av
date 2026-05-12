class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums,0,false);
    }

private:
    int dfs(vector<int>& nums, int index, bool subArrStarted) {
        if(index == nums.size()) {
            return subArrStarted ? 0 : -1e6;
        }
        if(subArrStarted) {
            return max(0,nums[index] + dfs(nums,index+1,true));
        }
        return max(dfs(nums,index+1,false), nums[index]+dfs(nums,index+1,true));
    }
};
