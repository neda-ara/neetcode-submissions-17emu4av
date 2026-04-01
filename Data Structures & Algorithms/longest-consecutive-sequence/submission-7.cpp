class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> numSet(nums.begin(),nums.end());

        for(int num : numSet) {
            if(numSet.find(num-1) == numSet.end()) {
                int len = 1;

                while(numSet.find(num+len) != numSet.end()) {
                    len++;
                }
                maxLen = max(maxLen,len);
            }
        }

        return maxLen;
    }
};
