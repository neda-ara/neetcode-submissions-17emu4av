class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n;

        // lower-bound = first element greater than or equal to
        while(l < r) { 
            int mid = l + (r-l)/2;

            if(target >= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l>0 && nums[l-1] == target ? l-1 : -1;
    }
};
