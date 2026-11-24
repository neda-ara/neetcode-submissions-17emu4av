class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0 || n == 1) {
            return n;
        }

        vector<pair<int,int>> cars;
        for(int i=0; i<n; i++) {
            int distLeft = target - position[i];
            cars.push_back({distLeft, speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> stk;

        for(auto car : cars) {
            double est = (double) car.first / car.second;
            if(stk.empty() || est > stk.top()) {
                stk.push(est);
            }
        }

        return stk.size();
    }
};
