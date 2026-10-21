class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int dupe = 0;

        for(int b=0; b<32; b++) {
            int x = 0, y = 0;
            int mask = 1 << b;

            for(int num=1; num<n; num++) {
                if(mask & num) {
                    x++;
                }
            }
            for(int i=0; i<n; i++) {
                if(mask & nums[i]) {
                    y++;
                }
            }

            if(y > x) {
                dupe |= mask;
            }
        }

        return dupe;
    }
};
