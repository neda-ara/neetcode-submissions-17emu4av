class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.empty()) {
            return -1;
        }

        int minn = nums[0];
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if(nums[l] <= nums[r]) {
                minn = min(minn, nums[l]);
            }

            int mid = l + (r-l)/2;
            minn = min(minn, nums[mid]);

            if(nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return minn;
    }
};
