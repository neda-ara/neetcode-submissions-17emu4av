class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int len = n1 + n2;

        int median1 = 0, median2 = 0, i = 0, j = 0;
        for (int count = 0; count <= (n1 + n2) / 2; count++) {
            median2 = median1;

            if (i < n1 && j < n2) {
                if (nums1[i] < nums2[j]) {
                    median1 = nums1[i];
                    i++;
                } else {
                    median1 = nums2[j];
                    j++;
                }
            } else if(i<n1) {
                median1 = nums1[i];
                i++;
            } else if(j<n2) {
                median1 = nums2[j];
                j++;
            }
        }

        if ((n1 + n2) % 2 == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return (double)median1;
        }
    }
};
