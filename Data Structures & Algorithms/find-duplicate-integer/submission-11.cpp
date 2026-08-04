class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while(low < high) {
            int mid = low + (high - low)/2;
            int lessOrEqual = 0;

            for(int num : nums) {
                if(num <= mid) {
                    lessOrEqual++;
                }
            }

            if(lessOrEqual > mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};
