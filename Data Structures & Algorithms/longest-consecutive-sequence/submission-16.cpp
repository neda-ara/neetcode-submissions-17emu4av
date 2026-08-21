class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(),nums.end());

        int res = 0;
        for(int num : nums) {
            int streak = 0, curr = num;
            if(lookup.count(curr-1) > 0) {
                continue;
            }
            while(lookup.count(curr) > 0) {
                streak++;
                curr++;
            }
            res = max(res,streak);
        }
        return res;
    }
};
