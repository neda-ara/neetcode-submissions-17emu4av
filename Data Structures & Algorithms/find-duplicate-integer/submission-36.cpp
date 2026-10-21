class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int l = 1, r = n-1;

        while(l < r) {
            int m = l + (r-l)/2;
            int lessOrEqual = 0;

            for(int i=0; i<n; i++) {
                if(nums[i] <= m) {
                    lessOrEqual++;
                }
            }

            if(lessOrEqual <= m) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return l;
    }
};
