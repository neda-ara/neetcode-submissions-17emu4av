class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n;

        while(l < r) {
            int m = l + (r-l)/2;

            if (target >= nums[m]) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return l > 0 && nums[l-1] == target ? l-1 : -1;
    }
};
