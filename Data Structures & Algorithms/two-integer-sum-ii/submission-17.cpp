class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++) {
            int comp = target - numbers[i];
            if(mpp.find(comp) != mpp.end()) {
                return {mpp[comp] + 1, i+1};
            } 
            mpp[numbers[i]] = i;
        }
        return {};
    }
};

