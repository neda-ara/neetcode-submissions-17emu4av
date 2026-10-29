class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int dupe = 0;

        for(int b=0; b<32; b++) {
            int x = 0, y = 0;

            int mask = 1 << b;

            for(int num : nums) {
                if(num & mask) {
                    x++;
                }
            }
            for(int i=1; i<n; i++) {
                if(i & mask) {
                    y++;
                }
            }
            if(x > y) {
                dupe |= mask;
            }

        }

        return dupe;
    }
};
