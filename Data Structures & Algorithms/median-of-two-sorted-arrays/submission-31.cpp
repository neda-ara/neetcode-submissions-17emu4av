class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if(A.size() > B.size()) {
            swap(A,B);
        }

        int n1 = A.size(), n2 = B.size();
        int len = n1 + n2;
        int half = (len+1)/2;

        int l = 0, r = n1;

        while(l <= r) {
            int i = l + (r-l)/2; 
            int j = half - i;

            int Aleft = i > 0 ? A[i-1] : INT_MIN;
            int Aright = i < n1 ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int Bright = j < n2 ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright) {
                if(len % 2 == 0) {
                    return (max(Aleft,Bleft) + min(Aright,Bright)) /2.0;
                } else {
                    return (double) max(Aleft,Bleft);
                }
            } else if (Bleft > Aright) {
                l = i+1;
            } else {
                r = i-1;
            }
        }

        return -1;
    }
};
