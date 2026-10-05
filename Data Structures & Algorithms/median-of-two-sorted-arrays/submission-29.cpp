class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int len = n1 + n2;

        int left = getKth(nums1,n1,0,nums2,n2,0,(len + 1) / 2);
        int right = getKth(nums1,n1,0,nums2,n2,0,(len + 2) / 2);

        return (left + right) / 2.0;
    }

    int getKth(vector<int>& a, int m, int i, vector<int>& b, int n, int j, int k) {
        if(m > n) {
            return getKth(b,n,j,a,m,i,k);
        }

        if(m == 0) {
            return b[j + k - 1];
        }

        if(k == 1) {
            return min(a[i],b[j]);
        }  

        int aIdx = min(m,k/2);
        int bIdx = min(n,k/2);

        if(a[i+aIdx-1] <= b[j+bIdx-1]) {
            return getKth(a,m-aIdx,i+aIdx,b,n,j,k-aIdx);
        } else {
            return getKth(a,m,i,b,n-bIdx,j+bIdx,k-bIdx);
        }
    }
};
