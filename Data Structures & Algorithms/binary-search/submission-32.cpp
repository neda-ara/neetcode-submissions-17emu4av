class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }

    int bs(vector<int>& nums, int& target, int l, int r) {
        if(l > r) {
            return -1;
        }

        int mid = l + (r-l)/2;
        if(nums[mid] == target) {
            return mid;
        }

        return nums[mid] > target ? bs(nums,target,l,mid-1) :
        bs(nums,target,mid+1,r);
    }
};
