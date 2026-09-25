class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.begin(),nums1.end());

        merged.insert(merged.end(),nums2.begin(),nums2.end());

        sort(merged.begin(),merged.end());

        int len = merged.size();
        int left = merged[(len - 1)/2];
        int right = merged[len/2];

        return (double) (left + (right-left)/2.0);
    }
};
