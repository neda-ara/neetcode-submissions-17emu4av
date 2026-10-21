class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n,0);

        for(int i=0; i<n; i++) {
           if(hash[nums[i]]) {
            return nums[i];
           } 
           hash[nums[i]]++;
        }

        return -1;
    }
};
