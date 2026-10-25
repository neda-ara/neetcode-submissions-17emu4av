class Solution {
public:
    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }

    int bs(vector<int>& nums, int target, int l, int r) {
        if(l > r) {
            return -1;
        }

        int m = l + (r-l)/2;
        if(nums[m] == target) {
            return m;
        }

        return target > nums[m] ? bs(nums,target,m+1,r) : bs(nums,target,l,m-1);  
    }
};
