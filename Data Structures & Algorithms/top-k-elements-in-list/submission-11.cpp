class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n+1);

        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        for(auto [num,frequency] : freq) {
            buckets[frequency].push_back(num);
        }

        vector<int> topK;

        for(int i=n; i>=1; i--) {
            for(int n : buckets[i]) {
                topK.push_back(n);
                if(topK.size() == k) {
                    return topK;
                }
            }
        }
        return topK;
    }
};
