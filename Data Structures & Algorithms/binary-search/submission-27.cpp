class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        // lower-bound = first element greater than or equal to
        while(l < r) { 
            int mid = l + (r-l)/2;

            if(target > nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l < n && nums[l] == target ? l : -1;
    }
};
