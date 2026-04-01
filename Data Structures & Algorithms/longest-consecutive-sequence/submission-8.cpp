class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int maxLen = 0;

        for(int num:nums) {
            if(!mpp[num]) {
                int left = mpp[num-1];
                int right = mpp[num+1];

                mpp[num] = left + right + 1;
                mpp[num-left] = mpp[num];
                mpp[num+right] = mpp[num];

                maxLen = max(maxLen,mpp[num]);
            }
        }

        return maxLen;
        
    }
};
