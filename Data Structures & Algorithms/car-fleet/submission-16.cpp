class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0 || n == 1) {
            return n;
        }

        vector<pair<int,int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());

        stack<double> fleets;
        double firstEta = (double) (target - cars[0].first) / cars[0].second;

        fleets.push(firstEta);

        for(int i=1; i<n; i++) {
            auto& car = cars[i];
            double currEta = (double) (target - car.first) / car.second;

            if(currEta > fleets.top()) {
                fleets.push(currEta);
            }
        }
        return fleets.size();
    }
};
