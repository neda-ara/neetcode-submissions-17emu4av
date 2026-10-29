class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int,int> idx;

        for(int i=0; i<n; i++) {
            int comp = target - numbers[i];
            if(idx.count(comp)) {
                return {idx[comp]+1,i+1};
            }
            idx[numbers[i]] = i;
        }

        return {};
    }
};
