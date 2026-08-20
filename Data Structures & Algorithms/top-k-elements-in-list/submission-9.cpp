class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        vector<pair<int,int>> pairs;
        for(auto [num,frequency] : freq) {
            pairs.push_back({frequency,num});
        }

        sort(pairs.rbegin(),pairs.rend());

        vector<int> topK;
        for(int i=0; i<k; i++) {
            topK.push_back(pairs[i].second);
        }

        return topK;
    }
};
