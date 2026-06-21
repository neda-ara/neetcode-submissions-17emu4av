class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int left = (len1+len2+1)/2;
        int right = (len1+len2+2)/2;

        int median1 = getKth(nums1,len1,nums2,len2,left,0,0);

        if(left == right) {
            return median1;
        } else {
            return (median1 + getKth(nums1,len1,nums2,len2,right,0,0)) / 2.0;
        }
    }

    int getKth(vector<int>& a, int m, vector<int>& b, int n, int k, int aStart, int bStart) {
        if(m > n) {
            return getKth(b, n, a, m, k, bStart, aStart);
        }
        if(m == 0) {
            return b[bStart + k - 1];
        }
        if(k==1) {
            return min(a[aStart],b[bStart]);
        }

        int i = min(m,k/2), j = min(n,k/2);

        if(a[aStart + i - 1] > b[bStart + j - 1]) {
            return getKth(a,m,b,n-j,k-j,aStart,bStart+j);
        } else {
            return getKth(a,m-i,b,n,k-i,aStart+i,bStart);
        }
    }
};
