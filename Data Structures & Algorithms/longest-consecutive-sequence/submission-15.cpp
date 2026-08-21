class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        
        sort(nums.begin(),nums.end());

        int curr = nums[0], res = 0, streak = 0, n = nums.size();

        for(int i=0; i<n;) {
            if(curr != nums[i]) {
                streak = 0;
                curr = nums[i];
            }
            while(i < n && nums[i] == curr) {
                i++;
            }
            streak++;
            curr++;
            res = max(res,streak);
        }
        return res;
    }
};
