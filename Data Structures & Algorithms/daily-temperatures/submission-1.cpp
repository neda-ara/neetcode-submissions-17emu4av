class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> mono;

        for(int i=0; i<n; i++) {
            int today = temperatures[i];

            while(!mono.empty() && mono.top().first < today) {
                pair<int,int> topPair = mono.top();
                result[topPair.second] = i - topPair.second;
                mono.pop(); 
            }

            mono.push({today,i});
        }

        return result;
    }
};
