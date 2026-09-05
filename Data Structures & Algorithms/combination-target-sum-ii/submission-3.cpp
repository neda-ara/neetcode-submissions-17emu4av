class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }

private:
    void dfs(int idx, vector<int> path, int total, vector<int>& candidates, 
    int target) {
        if(total == target) {
            res.push_back(path);
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(total + candidates[i] > target) {
                break;
            }
            path.push_back(candidates[i]);
            dfs(i+1, path, total+candidates[i], candidates, target);
            path.pop_back();
        }
    }
};
