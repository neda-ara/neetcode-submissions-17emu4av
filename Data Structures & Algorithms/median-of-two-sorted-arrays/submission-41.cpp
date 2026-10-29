class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), total = n1 + n2;

        int left = getKth(nums1,n1,0,nums2,n2,0,(total+1)/2);
        int right = getKth(nums1,n1,0,nums2,n2,0,(total+2)/2);

        return (left + right) / 2.0;
    }

    int getKth(vector<int>& nums1, int m, int i, vector<int>& nums2, int n, int j, int k) {
        if(m > n) {
            return getKth(nums2,n,j,nums1,m,i,k);
        }

        if(m == 0) {
            return nums2[j+k-1];
        }
        if(k == 1) {
            return min(nums1[i],nums2[j]);
        }

        int a = min(m,k/2), b = min(n,k/2);

        if(nums1[a+i-1] <= nums2[b+j-1]) {
            return getKth(nums1,m-a,i+a,nums2,n,j,k-a);
        } else {
            return getKth(nums1,m,i,nums2,n-b,j+b,k-b);
        }
    }
};
