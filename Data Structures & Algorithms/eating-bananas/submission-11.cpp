class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int speed = 0;

        while(l <= r) {
            int k = l + (r-l)/2;
            long long time = 0;

            for(int pile : piles) {
                time += (pile + k - 1)/k;
            }

            if(time <= h) {
                r = k - 1;
                speed = k;
            } else {
                l = k + 1;
            }
        }

        return speed;
    }
};
