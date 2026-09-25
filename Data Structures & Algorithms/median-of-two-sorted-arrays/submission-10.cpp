class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.begin(),nums1.end());

        merged.insert(merged.end(),nums2.begin(),nums2.end());

        sort(merged.begin(),merged.end());

        int leftIdx = merged.size()/2;
        int rightIdx = (merged.size() - 1)/2;

        return (double) (merged[leftIdx] + merged[rightIdx])/2.0;
    }
};
