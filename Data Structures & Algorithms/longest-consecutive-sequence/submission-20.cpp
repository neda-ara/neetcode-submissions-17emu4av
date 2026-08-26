class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(),nums.end());

        int res = 0;

        for(int num : nums) {
            int curr = num, streak = 0;
            if(!lookup.count(num-1)) {
                while(lookup.count(curr)) {
                    streak++;
                    curr++;
                }
            }
            res = max(res,streak);
        }
        return res;
    }
};
