class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int l=1, r = *max_element(piles.begin(),piles.end()); 
       int res = r;

       while(l <= r) {
        int k = (r-l)/2 + l;

        long long totalTime = 0;
        for(int pile : piles) {
            totalTime += (pile + k - 1)/k;
        }
        if(totalTime > h) {
           l = k+1;
        } else {
            res = k;
            r = k-1;
        }
       }
       return res;
    }
};

