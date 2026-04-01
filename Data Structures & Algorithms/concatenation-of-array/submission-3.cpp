class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(nums.begin(),nums.end());
        res.reserve(2*n);

        for(int i=0; i<n; i++) {
            res.push_back(nums[i]);
        }

        return res;
    }
};