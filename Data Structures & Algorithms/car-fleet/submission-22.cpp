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

        stack<double> stk;

        for(int i=0; i<n; i++) {
            auto& [distLeft, spd] = cars[i];
            double currEta = (double) distLeft / spd;

            if(stk.empty() || currEta > stk.top()) {
                stk.push(currEta);
            }
        }

        return stk.size();
    }
};
