class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        // Build adjacency list
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // prices[node][flightsTaken] = cheapest cost
        vector<vector<int>> prices(n, vector<int>(k + 2, INT_MAX));

        // queue stores {cost, airport, flights taken}
        queue<tuple<int, int, int>> q;

        q.push({0, src, 0});
        prices[src][0] = 0;

        while (!q.empty()) {
            auto [cost, node, flightsTaken] = q.front();
            q.pop();

            // Ignore outdated states
            if (cost > prices[node][flightsTaken]) {
                continue;
            }

            // Cannot take more than k intermediate stops
            if (flightsTaken == k + 1) {
                continue;
            }

            // explore outgoing flights
            for (const auto& [neighbor, price] : adj[node]) {
                int nextCost = cost + price;
                int nextFlights = flightsTaken + 1;

                if (nextCost < prices[neighbor][nextFlights]) {
                    prices[neighbor][nextFlights] = nextCost;
                    q.push({nextCost, neighbor, nextFlights});
                }
            }
        }

        int answer = INT_MAX;
        for (int f = 0; f <= k + 1; f++) {
            answer = min(answer, prices[dst][f]);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};
