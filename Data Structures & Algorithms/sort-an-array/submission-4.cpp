class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> count;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(auto& num : nums) {
            count[num]++;

            if(num > maxVal) {
                maxVal = num;
            }
            if(num < minVal) {
                minVal = num;
            }
        }

        int index = 0;

        for(int i = minVal; i <= maxVal; i++) {
            while(count[i] > 0) {
                nums[index] = i;
                index += 1;
                count[i] -= 1;
            }
        }

        return nums;
    }
};