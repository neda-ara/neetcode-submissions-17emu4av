class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0;
        if(n == 0) {
            return 0;
        } 

        unordered_set<int> all(nums.begin(), nums.end());
        sort(nums.begin(),nums.end());

        int i = 0, streak = 0, curr = nums[0];

        while(i < n) {
            if(nums[i] != curr) {
                streak = 0;
                curr = nums[i];
            }
            while(i < n && nums[i] == curr) {
                i++;
            }
            curr++;
            streak++;
            res = max(res,streak);
        }
        return res;
    }
};
