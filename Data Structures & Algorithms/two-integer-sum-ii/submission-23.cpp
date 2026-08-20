class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0; i<n; i++) {
            int complement = target - numbers[i];

            int l=i+1, r=n-1;
            while(l<=r) {
                int mid = (r-l)/2 + l;
                int midNum = numbers[mid];

                if(midNum == complement) {
                    return {i+1,mid+1};
                } else if (midNum > complement) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return {};
    }
};
