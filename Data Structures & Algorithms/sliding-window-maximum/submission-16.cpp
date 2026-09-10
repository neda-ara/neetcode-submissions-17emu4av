class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> output(n-k+1);
        vector<int> leftmax(n,nums[0]);
        vector<int> rightmax(n,nums[n-1]);


        for(int i=1; i<n; i++) {
            if(i % k == 0) {
                leftmax[i] = nums[i];
            } else {
                leftmax[i] = max(leftmax[i-1],nums[i]);
            }

            if((n-i-1) % k == 0) {
                rightmax[n-i-1] = nums[n-i-1]; 
            } else {
                rightmax[n-i-1] = max(rightmax[n-i],nums[n-i-1]);
            }
        }

        for(int i=0; i<n-k+1; i++) {
            output[i] = max(rightmax[i],leftmax[i+k-1]);
        }

        

        return output;
    }
};
