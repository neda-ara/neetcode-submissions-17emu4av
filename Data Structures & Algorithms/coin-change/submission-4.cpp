class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        queue<int> q;
        q.push(0);

        vector<bool> seen(amount + 1, false);
        seen[0] = true;

        int res = 0;

        while (!q.empty()) {
            res++;
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();

                for (int coin : coins) {
                    if (coin > amount - curr) {
                        continue;
                    }
                    int next = curr + coin;
                    if (next == amount) {
                        return res;
                    }
                    if (seen[next]) {
                        continue;
                    }
                    seen[next] = true;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};
