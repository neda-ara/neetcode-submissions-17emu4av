class Solution {
public:
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[left];
        int i = left;
        int j = right;

        while(i < j) {
            while(arr[i] <= pivot && i < right) {
                i++;
            }   
            while(arr[j] >= pivot && j > left) {
                j--;
            }
            if (i < j) swap(arr[i],arr[j]);
        }
        swap(arr[left], arr[j]);
        return j;
    }

    void quickSort(vector<int>& arr, int left, int right) {
        if(left < right) {
            int pivotIndex = partition(arr, left, right);
            quickSort(arr, left , pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
      quickSort(nums, 0, nums.size() - 1);
      return nums;  
    }
};