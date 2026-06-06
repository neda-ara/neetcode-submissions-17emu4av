class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        while(l < r) {
            int mid = (r-l)/2 + l;
            int midEl = nums[mid];

            if(target < midEl) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (l>0 && nums[l-1] == target ? l-1 : -1);
    }
};
