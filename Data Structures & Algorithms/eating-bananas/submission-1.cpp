class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end()); // O(n)
        int res = r;

        while(l <= r) { // O(n * logn)
            int mid = (r-l)/2 + l;
            long long totalTime = 0;

            for(int pile : piles) { // O(n)
                totalTime += (pile + mid - 1)/mid;
            }
            if(totalTime <= h) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
