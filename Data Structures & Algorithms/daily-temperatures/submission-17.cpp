class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> output(n,0);

        // iterate over input array in reverse order so we already have information of future days and we build the output list on reverse order to reuse them to skip unnecessary comparisions
        // so we check the first future day, if it is warmer that's our answer and if it is not then we check its value in output list to see after how many days this colder day reaches a warmer one so we skipover those many days in one jump bcz our answer will lie somewhere after that only. if a future colder day has 0 then it means we wont ever find a warmer day and can stop looking

        for(int i=n-2; i>=0; i--) {
            int j = i+1;
           while(j<n && temperatures[i] >= temperatures[j]) {
            if(output[j] == 0) {
                j = n;
                break;
            }
            j += output[j];
           }
           if(j != n) {
            output[i] = j-i;
           }
        }

        return output;
    }
};
