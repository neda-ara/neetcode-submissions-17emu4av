class Solution {
   public:
    int climbStairs(int n) {
        int waysToReachCurrStep = 1, waysToReachPrevStep = 1;

        for (int i = 0; i < n-1; i++) {
            int tmp = waysToReachCurrStep;
            waysToReachCurrStep = waysToReachCurrStep + waysToReachPrevStep;
            waysToReachPrevStep = tmp;
        }

        return waysToReachCurrStep;
    }
};
