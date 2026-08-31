class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size(), pivot = n, l = 0, r = n-1;

        while(pivot != n-k) {
            pivot = partition(nums,l,r);
            if(pivot < n-k) {
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }
        }
        return nums[pivot];
    }

    int partition(vector<int>& nums, int l, int r) {
        int pivotVal = nums[r], i = l;

        for(int j=l; j<r; j++) {
            if(nums[j] <= pivotVal) {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[r]);
        return i;
    }
};
