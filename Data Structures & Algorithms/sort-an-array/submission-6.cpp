class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int minVal = INT_MAX;
        int n = nums.size();

        // Find max val in array
        for(int i=0; i<n; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
            }
            if(nums[i] < minVal) {
                minVal = nums[i];
            }
        }

        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);

        // Populate count array
        for(int i=0; i<n; i++) {
            count[nums[i] - minVal]++;
        }

        // Calculate prefix count array
        for(int i=1; i<range; i++) {
            count[i] += count[i-1];
        }

        vector<int> sortedNums(n);

        // Populate sorted array
        for(int i=n-1; i>=0; i--) {
            int pos = --count[nums[i]-minVal];
            sortedNums[pos] = nums[i];
        }

        // Copy value from sorted array into original array
        for(int i=0; i<n; i++) {
            nums[i] = sortedNums[i];
        }

        return nums;
    }
};