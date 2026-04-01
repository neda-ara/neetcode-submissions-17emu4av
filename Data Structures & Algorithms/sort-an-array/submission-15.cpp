class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums; 

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(int i=0; i<n; i++) {
            if(nums[i] > maxVal) {
                maxVal = nums[i];
            } 
            if(nums[i] < minVal) {
                minVal = nums[i];
            }
        }

        // All elements same; hence arr already sorted
        if(minVal == maxVal) {
            return nums;
        }

        int bucketSize = n;
        vector<vector<int>> buckets(bucketSize);

        // Normalize each element into [0,1) and assign bucket
        for(int i=0; i<n; i++) {
            double normalized = double(nums[i] - minVal)/(maxVal - minVal);
            int idx = int(normalized * bucketSize);

            if(idx == bucketSize) idx--;
            buckets[idx].push_back(nums[i]);
        }

        // Sort each bucket (insertion sort)
        for(int b=0; b<bucketSize; b++) {
            for(int i=1; i<buckets[b].size(); i++) {
                int key = buckets[b][i];
                int j = i - 1;

                while(j >= 0 && buckets[b][j] > key) {
                    buckets[b][j+1] = buckets[b][j];
                    j--;
                }
                buckets[b][j+1] = key;
            }
        }

        // concatenate buckets back into arr
        int idx = 0;
        for(int b=0; b<bucketSize; b++) {
            for(double val :buckets[b]) {
                nums[idx++] = val;
            }
        }

        return nums;
    }
};