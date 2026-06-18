class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int totalLen = len1 + len2;
        int i = 0, j = 0, median1 = 0, median2 = 0;

        int pos1 = totalLen/2, pos2 = totalLen/2 - 1;

        for(int count = 0; count < totalLen/2+1; count++) {
            bool isPos1 = count == pos1;
            bool isPos2 = count == pos2;

            if(i < len1 && j < len2) {
                if(nums1[i] > nums2[j]) {
                    if(isPos2) {
                        median2 = nums2[j];
                    } else if (isPos1) {
                        median1 = nums2[j];
                    }
                    j++;
                } else {
                    if(isPos2) {
                        median2 = nums1[i];
                    } else if(isPos1) {
                        median1 = nums1[i];
                    }
                    i++;
                }
            } else if (i < len1) {
                if(isPos2) {
                    median2 = nums1[i];
                } else if(isPos1) {
                    median1 = nums1[i];
                }
                i++;
            } else if (j < len2) {
                if(isPos2) {
                    median2 = nums2[j];
                } else if(isPos1) {
                    median1 = nums2[j];
                }
                j++;
            }
        }

        if(totalLen % 2 == 1) {
            return (double) median1;
        } else {
            return (median1 + median2) / 2.0;
        }
    }
};
