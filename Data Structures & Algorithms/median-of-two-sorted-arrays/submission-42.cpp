class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if(A.size() > B.size()) {
            swap(A,B);
        }

        int n1 = A.size(), n2 = B.size(), total = n1 + n2;
        int half = (total+1)/2;

        int l = 0, r = n1;
        while(l <= r) {
            int i = l + (r-l)/2;
            int j = half - i;

            int Aleft = i > 0 ? A[i-1] : INT_MIN;
            int Aright = i < n1 ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int Bright = j < n2 ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright) {
                return total % 2 == 0 ?
                (max(Aleft,Bleft) + min(Aright,Bright)) / 2.0 :
                (double) max(Aleft,Bleft);
            } else if (Aleft > Bright) {
                r = i-1;
            } else {
                l = i+1;
            }
        }

    }
};
