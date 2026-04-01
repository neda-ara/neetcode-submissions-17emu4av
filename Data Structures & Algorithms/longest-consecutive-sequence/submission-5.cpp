class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> store(nums.begin(),nums.end());

        int maxLength = 0;

        for(int num : nums) {
            int streak = 0, curr = num;

            while(store.find(curr) != store.end()) {
                curr++;
                streak++;
            }

            maxLength = max(maxLength, streak);
        }

        return maxLength;
    }
};
