class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0 || n == 1) {
            return n;
        }

        vector<pair<int,int>> cars;
        for(int i=0; i<n; i++) {
            cars.push_back({target-position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        int fleets = 1;
        double prevTime = cars[0].first / cars[0].second;

        for(int i=1; i<n; i++) {
            pair<int,int> car = cars[i];
            double currTime = (double) car.first / car.second;

            if(currTime > prevTime) {
                prevTime = currTime;
                fleets++;
            }
        }

        return fleets;
    }
};
