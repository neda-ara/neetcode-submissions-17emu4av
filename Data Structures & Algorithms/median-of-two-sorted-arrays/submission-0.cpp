class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> merged(len1+len2);

        copy(nums1.begin(),nums1.end(),merged.begin()); // O(n)
        copy(nums2.begin(),nums2.end(),merged.begin()+len1); // O(m)

        sort(merged.begin(),merged.end());
        int sz = merged.size();

        if(sz % 2 == 0) {
            return (merged[sz/2] + merged[sz/2 - 1])/2.0;
        } 
        return merged[sz/2];
    }
};
