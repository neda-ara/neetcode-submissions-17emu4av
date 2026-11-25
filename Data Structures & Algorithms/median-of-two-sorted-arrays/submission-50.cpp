class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2;

        int k1 = (total + 1)/2;
        int k2 = (total + 2)/2;

        int median1 = getKth(nums1, n1, 0, nums2, n2, 0, k1);
        int median2 = getKth(nums1, n1, 0, nums2, n2, 0, k2);

        return total % 2 == 0 ? (median1 + median2) / 2.0 : (double)median1;
    }

    int getKth(vector<int>& nums1, int n1, int a, vector<int>& nums2, int n2, int b, int k) {
        if(n1 > n2) {
            return getKth(nums2, n2, b, nums1, n1, a, k); 
        }

        if(n1 == 0) {
            return nums2[b+k-1];
        }
        if(k == 1) {
            return min(nums1[a], nums2[b]);
        }

        int i = min(n1,k/2), j = min(n2,k/2);

        if(nums1[a+i-1] <= nums2[b+j-1]) {
            return getKth(nums1, n1-i, a+i, nums2, n2, b, k-i);
        } else {
            return getKth(nums1, n1, a, nums2, n2-j, b+j, k-j);
        }

    }
};
