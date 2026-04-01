class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0; i<n; i++) {
            int l = i+1, r = n-1;
            int searchVal = target - numbers[i];

            while(l <= r) {
                int mid = (l+r)/2;

                if(searchVal > numbers[mid]) {
                    l = mid+1;
                } else if (searchVal < numbers[mid]) {
                    r = mid-1;
                } else {
                    return {i+1,mid+1};
                }
            }
        }

        return {};   
    }
};
