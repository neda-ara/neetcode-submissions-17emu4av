class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;

        int n = nums.size();
        if(n == 0) {
            return {};
        }

        vector<int> left(n,nums[0]);
        vector<int> right(n,nums[n-1]);

        for(int i=1; i<n; i++) {
            if(i % k == 0) {
                left[i] = nums[i];
            } else {
                left[i] = max(left[i-1],nums[i]);
            }
            if((n-i-1) % k == 0) {
                right[n-i-1] = nums[n-i-1];
            } else {
                right[n-i-1] = max(right[n-i],nums[n-i-1]);
            }
        }

        for(int i=0; i<n-k+1; i++) {
            output.push_back(max(right[i],left[i+k-1]));
        }

        return output;
    }
};
