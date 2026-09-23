class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;
        while(l < r) {
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        int pivot = l;
        int result = binarySearch(nums,0,pivot-1,target);
        if(result != -1) {
            return result;
        }
        return binarySearch(nums,pivot,n-1,target);   
    }

    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
