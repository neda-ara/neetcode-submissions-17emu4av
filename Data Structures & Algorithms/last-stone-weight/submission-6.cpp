class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());

        int n = stones.size();

        while(n > 1) {
            int diff = stones[n-1] - stones[n-2];
            n -= 2;

            if(diff == 0) {
                continue;
            }

            int l=0, r = n;
            while(l < r) {
                int mid = (l+r) >> 1;

                if(stones[mid] > diff) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            int pos = l;
            stones.push_back(0);

            for(int i=n+1; i>pos; i--) {
                stones[i] = stones[i-1];
            }
            stones[pos] = diff;
            n++;
        }

        return n == 0 ? 0 : stones[0];
    }
};
