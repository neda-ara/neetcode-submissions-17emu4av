class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup;
        int res = 0;

        for(int num : nums) {
            lookup.insert(num);
        }

        for(int num : nums) {
            int curr = num, streak = 0;
            if(!lookup.count(curr-1)) {
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
