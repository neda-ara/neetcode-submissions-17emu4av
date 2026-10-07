class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;

        int n = nums.size(), res = 0;

        for(int num : nums) {
            if(!mpp[num]) {
                int left = mpp[num-1], right = mpp[num+1];

                mpp[num] = mpp[num-1] + 1 + mpp[num+1];
                mpp[num - left] = mpp[num];
                mpp[num + right] = mpp[num];

                res = max(res,mpp[num]);
            }
        }

        return res;
    }
};
