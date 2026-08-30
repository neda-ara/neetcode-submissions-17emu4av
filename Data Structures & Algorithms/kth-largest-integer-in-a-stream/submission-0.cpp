class KthLargest {
public:
    vector<int> arr;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->arr = nums;
        this->k = k;
    }
    
    int add(int val) {
        arr.push_back(val);
        sort(arr.rbegin(),arr.rend());
        return arr[k-1];
    }
};
