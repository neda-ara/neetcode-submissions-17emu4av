class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        vector<int> merged(nums1.begin(),nums1.end());
        
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(),merged.end());

        int total = merged.size();

        return total % 2 == 0 ?
            (merged[(total/2) - 1] + merged[total/2]) / 2.0 :
            (double) merged[total/2]; 
    }
};
