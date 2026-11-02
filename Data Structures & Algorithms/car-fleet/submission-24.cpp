class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0 || n == 1) {
            return n;
        }

        vector<pair<int,int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({target - position[i], speed[i]});
        }

        sort(cars.begin(),cars.end());

        int fleets = 0;
        double prevEta = 0.0;

        for(int i=0; i<n; i++) {
            auto& [distLeft, spd] = cars[i];
            double currEta = (double) distLeft / spd;

            if(currEta > prevEta) {
                prevEta = currEta;
                fleets++;
            }
        }

        return fleets;
    }
};
