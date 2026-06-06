class Solution {
public:
    int binary_search(vector<int>& nums, int l, int r, int target) {
        if(l > r) {
            return -1;
        }

        int mid = (r-l)/2 + l;
        int midEl = nums[mid];

        if(target == midEl) {
            return mid;
        }
        return target > midEl 
            ? binary_search(nums,mid+1,r,target) 
            : binary_search(nums,l,mid-1,target);
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums,0,nums.size()-1,target);
    }
};
