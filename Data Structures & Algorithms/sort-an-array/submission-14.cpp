class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for(int gap=n/2; gap>=1; gap/=2) {
            for(int j=gap; j<n; j++) {
                for(int i=j-gap; i>=0; i--) {
                    if(nums[i+gap] > nums[i]) {
                        break;
                    } else {
                        swap(nums[i+gap], nums[i]);
                    }
                }
            }
        }

        return nums;
    }
};