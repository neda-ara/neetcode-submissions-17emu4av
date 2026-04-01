class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n,false);

        for(int num : nums) {
            if(num > 0 && num <= n) {
                seen[num-1] = true;
            }
        }

        for(int i=0; i<n; i++) {
            if(!seen[i]) {
                return i + 1;
            }
        }

        // if arrat has all numbers from 1 to n, smallest missing +ve would be the next no.
        return n+1; 
    }
};