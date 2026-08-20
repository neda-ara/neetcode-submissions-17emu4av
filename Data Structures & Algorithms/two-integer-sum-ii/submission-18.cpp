class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while(l < r) {
            int currSum = numbers[l] + numbers[r];

            if(currSum == target) {
                return {l+1,r+1};
            } else if (currSum > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
