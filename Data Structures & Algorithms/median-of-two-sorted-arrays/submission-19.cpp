class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), len = n1+n2;

        int left = (len+1)/2;
        int right = (len+2)/2;

        return (getKth(nums1,n1,0,nums2,n2,0,left) + getKth(nums1,n1,0,nums2,n2,0,right)) / 2.0;
    }

    int getKth(vector<int>& a, int m, int aStart, vector<int>& b, int n, int bStart, int k) {
        if(m > n) {
            return getKth(b,n,bStart,a,m,aStart,k);
        }

        if(m == 0) {
            return b[bStart + k - 1];
        }
        if(k==1) {
            return min(a[aStart],b[bStart]);
        }

        int i = min(m,k/2), j = min(n,k/2);

        if(a[aStart+i-1] < b[bStart+j-1]) {
            return getKth(a,m-i,aStart+i,b,n,bStart,k-i);
        } else {
            return getKth(a,m,aStart,b,n-j,bStart+j,k-j);
        }
    }
};
