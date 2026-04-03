class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> mpp;
        int n = numbers.size();

        vector<int> ans = {INT_MAX,INT_MAX};

        for(int i=0; i<n; i++) {
            int complement = target - numbers[i];

            if(mpp.find(complement) != mpp.end()) {
                int idx1 = mpp[complement] + 1;
                int idx2 = i + 1;

                if(idx1<ans[0] || (idx1==ans[0] && idx2<ans[1])) {
                    ans = {idx1,idx2};
                }
            }
            if(mpp.find(numbers[i]) == mpp.end()){
                mpp[numbers[i]] = i;
            }
        }
        return ans;
    }
};
