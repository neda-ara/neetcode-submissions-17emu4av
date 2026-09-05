class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = 0;

        unordered_map<int,int> mpp;
        
        for(int num : nums) {
            if(!mpp[num]) {
                mpp[num] = mpp[num-1] + mpp[num+1] + 1;
                mpp[num - mpp[num-1]] = mpp[num];
                mpp[num + mpp[num+1]] = mpp[num];

                len = max(len,mpp[num]);
            }
        }
        return len;
    }
};
