class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++) {

            // at any index i of arr, the correct no is i+1
            // for any num at index i, its correct place is num - 1
            // every num at index i, we swap it with the no. at its correct position till for the num at curr i is not correct
            // we ignore -ve numbers and zero, they can end up wherever

            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // After all swappings, the first index that doesn't have its correct num is the missing no - 1
        for(int i=0; i<n; i++) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }

        // If all are at correct place, then the next no in sequence is the smallest missing +ve
        return n+1;
    }
};