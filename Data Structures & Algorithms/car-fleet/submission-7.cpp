class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;

        int n = position.size();
        if(n == 0 || n == 1) {
            return n;
        }

        for(int i=0; i<n; i++) {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());

        stack<double> stk;
        stk.push((double)(target - cars[0].first) / cars[0].second);

        for(int i=1; i<n; i++) {
            auto car = cars[i];
            double currETA = (double) (target - car.first) / car.second;

            if(!stk.empty() && currETA > stk.top()) {
                stk.push(currETA);
            }
        }

        return stk.size();
    }
};
