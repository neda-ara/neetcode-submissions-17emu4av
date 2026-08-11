class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vec;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());

        int i=0, j = n-1;
        while(i < j) {
            int curr = vec[i].first + vec[j].first;
            if(curr > target) {
                j--;
            } else if(curr < target) {
                i++;
            } else if(curr == target) {
                return {min(vec[i].second,vec[j].second),max(vec[i].second,vec[j].second)};
            }
        }

        return {};
    }
};
