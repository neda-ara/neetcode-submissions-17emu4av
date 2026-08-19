class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++) {
            arr.push_back({nums[i],i});
        }

        sort(arr.begin(),arr.end());

        int l = 0, r = n-1;

        while(l < r) {
            int curr = arr[l].first + arr[r].first;
            if(curr == target) {
                return {
                    min(arr[l].second,arr[r].second),
                    max(arr[l].second,arr[r].second)
                };
            } else if (curr > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
