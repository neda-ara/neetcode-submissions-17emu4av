class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());
        int res = r;

        while (l < r) {
            int mid = l + (r-l)/2;
            long long totalTime = 0;
            
            for(int pile : piles) {
                totalTime += (pile + mid - 1)/mid;
            }

            if(totalTime > h) {
                l = mid + 1;
            } else {
                r = mid;
                res = mid;
            }
        }

        return res;
    }
};
