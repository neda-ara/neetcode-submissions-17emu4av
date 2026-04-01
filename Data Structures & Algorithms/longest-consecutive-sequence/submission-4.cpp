class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxLength = n > 0 ? 1 : 0;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++) {
            int currLength = 1;
            for(int j=i+1; j<n; j++) {
                if(nums[j] == nums[j-1]) {
                    continue;
                } else if (nums[j] == nums[j-1] + 1) {
                    currLength++;
                } else {
                    break;
                }
            }
            maxLength = max(currLength, maxLength);
        }

        return maxLength;
    }
};
