class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;

        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,curr,0);
        return res;
    }

private: 
    void dfs(vector<int>& candidates, int target, int i, 
    vector<int>& curr, int total) {
        if(total == target) {
            res.push_back(curr);
            return;
        }
        if(total > target || i == candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]);
        dfs(candidates,target,i+1,curr,total+candidates[i]);

        curr.pop_back();
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
            i++;
        }
        dfs(candidates,target,i+1,curr,total);
    }
};
