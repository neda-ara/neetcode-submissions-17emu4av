class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> result;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i != j && (numbers[i] + numbers[j] == target)) {
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
            }
        }
    }
};
