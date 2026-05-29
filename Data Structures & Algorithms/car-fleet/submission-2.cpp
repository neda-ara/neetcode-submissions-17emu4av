class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;

        for(int i=0; i<n; i++) {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(),cars.rend());

        stack<double> stk;

        for(auto& c : cars) {
            double timeNeeded = (double) (target - c.first) / c.second;

            if(stk.empty() || timeNeeded > stk.top()) {
                stk.push(timeNeeded);
            }
        }
        return stk.size();
    }
};
