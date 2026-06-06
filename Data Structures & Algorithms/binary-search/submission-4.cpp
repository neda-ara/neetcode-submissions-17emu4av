class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        while(l < r) {
            int mid = (r-l)/2 +l;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                 l = mid + 1;
            }
        }
        return l < nums.size() && nums[l] == target ? l : -1;
    }
};
