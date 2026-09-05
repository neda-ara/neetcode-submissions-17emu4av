class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), len = 0;

        unordered_set<int> lookup(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
            int streak = 1;

            if(!lookup.count(nums[i]-1)) {
                while(lookup.count(nums[i]+streak)) {
                    streak++;
                }
            }

            len = max(len,streak);
        }   
        return len;
    }
};
