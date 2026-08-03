class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);

        for(int i=0; i<n; i++) {
            arr[nums[i]]++;
        }

        for(int i=1; i<n; i++) {
            if(arr[i] > 1) {
                return i;
            }
        }

        return -1;
    }
};
