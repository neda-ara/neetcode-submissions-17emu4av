class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int len = 0;

        for (int& num : nums) {
            if (!mpp[num]) {
                int left = mpp[num - 1];
                int right = mpp[num + 1];

                mpp[num] = 1 + left + right;
                mpp[num - left] = mpp[num];
                mpp[num + right] = mpp[num];
                len = max(mpp[num], len);
            }
        }

        return len;
    }
};
