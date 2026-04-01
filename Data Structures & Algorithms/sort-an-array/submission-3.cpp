class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

private:
    void heapSort(vector<int>& arr){
        int n = arr.size();

        // Build max heap
        for(int i = n/2-1; i>=0; i--) {
            heapify(arr, n, i);
        }

        // Retrieve sorted array from max heap
        for(int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

private:
    void heapify(vector<int>& arr, int n, int i) {
        int l = (i << 1) + 1; // equiv to i*2; miro-optimization
        int r = (i << 1) + 2;
        int largestNode = i;

        if(l < n && arr[l] > arr[largestNode]) {
            largestNode = l;
        }
        if(r < n && arr[r] > arr[largestNode]) {
            largestNode = r;
        }

        if(largestNode != i) {
            swap(arr[i], arr[largestNode]);
            heapify(arr, n, largestNode);
        }
    }
};