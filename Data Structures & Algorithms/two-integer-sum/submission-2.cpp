class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numIndexPairs;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            numIndexPairs.push_back({nums[i],i});
        }

        sort(numIndexPairs.begin(),numIndexPairs.end());

        int left = 0, right = n - 1;

        while(left < right) {
            int curr = numIndexPairs[left].first + numIndexPairs[right].first;

            if(curr == target) {
                int minIdx = min(numIndexPairs[left].second, numIndexPairs[right].second);
                int maxIdx = max(numIndexPairs[left].second, numIndexPairs[right].second);
                return {minIdx,maxIdx};
            } else if (curr > target) {
                right--;
            } else {
                left++;
            }
        }

        return {};
    }
};
