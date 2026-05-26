class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);

        for(int i=n-2; i>=0; i--) {
            int j = i+1;

            while(j<n && temperatures[i] >= temperatures[j]) {
                if(result[j] == 0) {
                    j = n;
                    break;
                }
                j += result[j];
            }
            if(j < n) {
                result[i] = j - i;
            }
        }
        return result;
    }
};
