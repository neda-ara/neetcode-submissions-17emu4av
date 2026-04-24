class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> temp;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            temp.push_back({nums[i],i});
        }


        sort(temp.begin(), temp.end());

        int l=0, r=n-1;
        while(l < r) {
            int currSum = temp[l].first + temp[r].first;

            if(currSum > target) {
                r--;
            } else if (currSum < target) {
                l++;
            } else {
                int firstIdx = temp[l].second;
                int secondIdx = temp[r].second;

                return {min(firstIdx,secondIdx),max(firstIdx,secondIdx)};
            }
        } 
        return {};
    }
};
