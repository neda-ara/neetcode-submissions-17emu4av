class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());

        while(l < r) {
            long long time = 0;

            int k = l + (r-l)/2;

            for(int pile : piles) {
                time += (pile + k - 1) / k;
            }

            if(time > h) {
                l = k + 1;
            } else {
                r = k;
            }

        }
        return l;
    }
};
