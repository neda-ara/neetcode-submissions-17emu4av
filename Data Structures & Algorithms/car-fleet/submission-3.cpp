class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
         int n = position.size();
         vector<pair<int,double>> cars;

         for(int i=0; i<n; i++) {
            double timeReq = (double) (target-position[i])/speed[i];
            cars.push_back({position[i],timeReq});
         }
         sort(cars.rbegin(),cars.rend());

         stack<double> fleetTimes;
         for(auto& c : cars) {
            if(fleetTimes.empty() || c.second > fleetTimes.top()) {
                fleetTimes.push(c.second);
            }
         }
         return fleetTimes.size();
    }
};
