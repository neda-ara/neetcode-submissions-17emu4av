class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorEl = 0, count = 0;

        for(int num : nums) {
            if(count == 0) {
                majorEl = num;
            }

            count += (num == majorEl) ? 1 : -1;
        }

        return majorEl;
    }
};