class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        int res = 0;

        for(int num : nums) {
            lookup.insert(num);
        }

        for(int num : nums) {
            int streak = 0;
            if(!lookup.count(num-1)) {
                while(lookup.count(num+streak)) {
                    streak++;
                }
            }
            res = max(res,streak);
        }
        return res;
    }
};
