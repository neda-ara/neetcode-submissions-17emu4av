class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while(l < r) {
            int mid = (l+r) >> 1;
            if(nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return (r < nums.size() && nums[r] == target) ? r : -1;
    }

    
};
