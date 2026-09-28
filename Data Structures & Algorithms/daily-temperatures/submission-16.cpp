class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> output(n,0);
        stack<int> idx;

        // use a monotonic stack and store idx of temperatures in increasing order. idx because eventually we need to calculate the difference in days
        // everytime we encounter a temp more than the last stored one, this acts as a warmer day for previously stored ones so calculate the diff in days for prev ones then pop them then store this
        // for days in stack with no warmer future days we return0 for them

        for(int i=0; i<n; i++) {
            while(!idx.empty() && temperatures[i] > temperatures[idx.top()]) {
                output[idx.top()] = i - idx.top();
                idx.pop();
            }
            idx.push(i);
        }

        return output;
    }
};
