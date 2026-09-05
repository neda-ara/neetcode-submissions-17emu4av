class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int,int> count;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<int> uniques;

        for(int candidate : candidates) {
            if(!count[candidate]) {
                uniques.push_back(candidate);
            }
            count[candidate]++;
        }

        backtrack(uniques,target,curr,0);
        return res;
    }

private:
    void backtrack(vector<int>& nums, int target, vector<int>& curr, int i) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }

        if(target < 0 || i >= nums.size()) {
            return;
        }

        if(count[nums[i]]) {
            curr.push_back(nums[i]);
            count[nums[i]]--;

            backtrack(nums,target-nums[i],curr,i);
            count[nums[i]]++;
            curr.pop_back();
        }
        backtrack(nums,target,curr,i+1);
    }
};
