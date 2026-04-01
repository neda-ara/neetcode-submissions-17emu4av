class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l = 0, r = n - 1;

        while(l < r) {
            int currSum = numbers[l] + numbers[r];

            if(currSum > target) {
                r--;
            } else if(currSum < target) {
                l++;
            } else {
                return {l+1, r+1};
            }
        }
    }
};
