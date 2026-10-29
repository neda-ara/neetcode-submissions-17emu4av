class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int l=1, r=n-1;

        while(l < r) {
            int mid = l + (r-l)/2;
            int lessOrEqual = 0;

            for(int num : nums) {
                if(num <= mid) {
                    lessOrEqual++;
                }
            }

            if(lessOrEqual <= mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};
