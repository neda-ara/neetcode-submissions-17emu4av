class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n,0);

        for(int num : nums) {
            if(arr[num-1] != 0) {
                return num;
            }
            arr[num-1]++;
        }

        return -1;
    }
};
