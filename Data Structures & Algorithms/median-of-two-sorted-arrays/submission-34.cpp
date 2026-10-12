class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2;

        int median1 = 0, median2 = 0;
        int i = 0, j = 0;

        for(int cnt=0; cnt<=total/2; cnt++) {
            median2 = median1;

            if(i < n1 && j < n2) {
                if(nums1[i] <= nums2[j]) {
                    median1 = nums1[i];
                    i++;
                } else {
                    median1 = nums2[j];
                    j++;
                }
            } else if(i < n1) {
                median1 = nums1[i];
                i++;
            } else {
                median1 = nums2[j];
                j++;
            }
        }

        return total % 2 == 0 ? (median1 + median2) / 2.0 : (double) median1;
    }
};
