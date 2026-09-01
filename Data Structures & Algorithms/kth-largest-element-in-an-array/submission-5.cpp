class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums,k-1);
    }

private:
    int quickselect(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;

        while(true) {
            if(right <= left+1) {
                if(right == left+1 && nums[right] > nums[left]) {
                    swap(nums[left],nums[right]);
                }
                return nums[k];
            }
            int j = partition(nums,left,right);

            if(j > k) {
                right = j-1;
            } else if (j < k) {
                left = j + 1;
            } else {
                return nums[k];
            }
        } 
    }

    int partition(vector<int>& nums, int l, int r) {
        int mid = (l+r) >> 1;
        swap(nums[mid],nums[l+1]);

        if(nums[l] < nums[r]) {
            swap(nums[l],nums[r]);
        } 
        if(nums[l+1] < nums[r]) {
            swap(nums[l+1],nums[r]);
        }
        if(nums[l] < nums[l+1]) {
            swap(nums[l+1],nums[l]);
        }

        int pivot = nums[l+1], i = l+1, j = r;

        while(true) {
            while(nums[++i] > pivot);
            while(nums[--j] < pivot);
            if(i > j) {
                break;
            }
            swap(nums[i],nums[j]);
        }

        nums[l+1] = nums[j];
        nums[j] = pivot;
        return j;
    }
};
