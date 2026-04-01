class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
     int maxVal = INT_MIN;
     int minVal = INT_MAX;
     int n = nums.size();

     for(int i=0; i<n; i++) {
        if(nums[i] > maxVal) {
            maxVal = nums[i];
        }
        if(nums[i] < minVal) {
            minVal = nums[i];
        }
     }  

    int shift = (minVal < 0) ? -minVal : 0;

    if(shift > 0) {
        for(int i=0; i<n; i++) {
            nums[i]+=shift;
        }
        maxVal+=shift;
    }

     for(int exp=1; maxVal/exp > 0; exp*=10) {
        countSort(nums, n, exp);
     }

     if(shift > 0) {
        for(int i=0; i<n; i++) {
            nums[i] -= shift;
        }
     }

     return nums;
}

private:
    void countSort(vector<int>& arr, int n, int exp) {
        vector<int> sortedArr(n);
        vector<int> count(10, 0);

        for(int i=0; i<n; i++) {
            count[(arr[i]/exp)%10]++;
        }
        for(int i=1; i<10; i++) {
            count[i]+=count[i-1];
        }
        for(int i=n-1; i>=0; i--) {
            int digit = (arr[i]/exp)%10;
            sortedArr[--count[digit]] = arr[i];
        }
        for(int i=0; i<n; i++) {
            arr[i] = sortedArr[i];
        }
    }
};