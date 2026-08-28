class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), water = 0;

        vector<int> prefix(n,0);
        vector<int> suffix(n,0);

        for(int i=1; i<n; i++) {
            prefix[i] = max(prefix[i-1],height[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
            suffix[i] = max(suffix[i+1],height[i+1]);
        }

        for(int i=0; i<n; i++) {
            int effective_height = min(prefix[i],suffix[i]) - height[i];
            water += max(0,effective_height);
        }
        return water;
    }
};
