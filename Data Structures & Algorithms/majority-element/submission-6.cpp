class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        while(true) {
            int candidate = nums[rand() % n];
            int count = 0;

            for(int num : nums) {
                if(candidate == num) {
                    count++;
                }
                if(count > n/2) {
                    return candidate;
                }
            }
        }
    }
};