class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = (l+r) >> 1;
            if(nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return (r > 0 && nums[r-1] == target) ? r-1 : -1;
    }

    
};
