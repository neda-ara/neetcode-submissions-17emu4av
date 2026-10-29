class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1+n2;

        vector<int> merged(nums1.begin(),nums1.end());
        merged.insert(merged.end(),nums2.begin(),nums2.end());
        sort(merged.begin(),merged.end());

        if(total%2 == 0) {
            return (merged[total/2] + merged[(total/2)-1]) / 2.0;
        } else {
            return (double) merged[total/2];
        }
    }
};
