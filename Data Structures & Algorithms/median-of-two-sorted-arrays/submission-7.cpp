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
        vector<int>* pa = &a;
        vector<int>* pb = &b;

        while(true) {
            if(m > n) {
                swap(pa,pb);
                swap(m,n);
                swap(aStart,bStart);
            }

            if(m==0) {
                return (*pb)[bStart + k - 1];
            }

            if(k==1) {
                return min((*pa)[aStart],(*pb)[bStart]);
            }

            int i = min(m,k/2), j = min(n,k/2);
            if((*pa)[aStart+i-1] > (*pb)[bStart+j-1]) {
                n -= j;
                k -= j;
                bStart += j;
            } else {
                m -= i;
                k -= i;
                aStart += i;
            }
        }
    }
};
