class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums,target,0,nums.size()-1);
    }

    int binary_search(vector<int>& nums, int target, int l, int r) {
        if(l > r) {
            return -1;
        }

        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            return mid;
        }

        return nums[mid] > target
                ? binary_search(nums,target,l,mid-1)
                : binary_search(nums,target,mid+1,r);
    }
};
