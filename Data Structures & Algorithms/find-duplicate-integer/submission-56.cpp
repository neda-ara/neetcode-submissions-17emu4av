class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        vector<bool> visited(n, false);

        for (int& num : nums) {
            if (visited[num]) {
                return num;
            }
            visited[num] = true;
        }

        return -1;
    }
};
