class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> arr(nums.begin(),nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(arr[i] < 0) {
                arr[i] = 0;
            }
        }

        for(int i=0; i<n; i++) {
            int val = abs(arr[i]);

            if(val > 0 && val <= n) {
                if(arr[val - 1] > 0) {
                    arr[val - 1] *= -1;
                } else if(arr[val - 1] == 0) {
                    arr[val - 1] = -1 * (n+1);
                }
            }
        }

        for(int i=0; i<n; i++) {
            if(arr[i] >= 0) {
                return i+1;
            }
        }

        return n+1;
    }
};