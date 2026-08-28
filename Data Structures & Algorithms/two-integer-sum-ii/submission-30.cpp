class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        unordered_map<int,int> indices;
        for(int i=0; i<n; i++) {
            int comp = target - numbers[i];
            if(indices.count(comp)) {
                return {indices[comp]+1,i+1};
            }
            indices[numbers[i]] = i;
        }
        return {};
    }
};
