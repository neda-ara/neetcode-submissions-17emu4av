class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int missing = 1;

        for(int num : nums) {
            if(missing < num) return missing;
            if(num > 0 && num == missing) {
            // increment possible candidate by 1 for next iteration if current candiate is found
               missing++;
            }
        }

        return missing;
    }
};