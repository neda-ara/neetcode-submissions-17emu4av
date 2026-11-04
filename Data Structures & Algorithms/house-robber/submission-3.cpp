class Solution {
   public:
    int rob(vector<int>& nums) {
        int robPrev = 0, robSecondPrev = 0;

        for (int num : nums) {
            int robCurr = max(robPrev, num + robSecondPrev);
            robSecondPrev = robPrev;
            robPrev = robCurr;
        }
        return robPrev;
    }
};
