class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int len = n1+n2;

        vector<int> merged(nums1.begin(),nums1.end());

        merged.insert(merged.end(),nums2.begin(),nums2.end());
        sort(merged.begin(),merged.end());

        if (len % 2 == 0) {
            return (merged[len/2 - 1] + merged[len/2]) / 2.0;
        } else {
            return (double) merged[len/2];
        }
    }
};
