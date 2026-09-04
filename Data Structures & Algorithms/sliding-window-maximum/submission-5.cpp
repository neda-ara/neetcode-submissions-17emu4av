class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftmax(n);
        vector<int> rightmax(n);

        leftmax[0] = nums[0];
        rightmax[n-1] = nums[n-1];

        for(int i=1; i<n; i++) {
            if(i%k == 0) {
                leftmax[i] = nums[i];
            } else {
                leftmax[i] = max(leftmax[i-1],nums[i]);
             }

             if((n-1-i) % k == 0) {
                rightmax[n-1-i] = nums[n-1-i];
             } else {
                rightmax[n-1-i] = max(rightmax[n-i],nums[n-1-i]);
             }
        }

        vector<int> output(n-k+1);
        for(int i=0; i<n-k+1; i++) {
            output[i] = max(leftmax[i+k-1], rightmax[i]);
        }

        return output;
    }
};
