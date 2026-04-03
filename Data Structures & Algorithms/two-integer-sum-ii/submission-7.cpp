class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for(int i=0; i<n; i++) {
            int complement = target - numbers[i];
            int l=i+1, r=n-1;
            
            while(l<=r){
                int mid = l + (r-l)/2;
                if(numbers[mid] == complement) {
                    return {i+1, mid+1};
                } else if(numbers[mid] > complement) {
                    r = mid-1;
                } else {
                    l= mid+1;
                }
            }
        }
        return {};
    }
};
