class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n, 0);

        for (int& num : nums) {
            if (arr[num]) {
                return num;
            }
            arr[num] = num;
        }

        return -1;
    }
};
