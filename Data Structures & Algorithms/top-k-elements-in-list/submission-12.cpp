class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        for(int num : nums) {
            frequency[num]++;
        }

        vector<pair<int,int>> arr;
        for(auto [num,freq] : frequency) {
            arr.push_back({freq,num});
        }

        sort(arr.rbegin(),arr.rend());

        vector<int> topK;
        for(int i=0; i<k; i++) {
            topK.push_back(arr[i].second);
        }

        return topK;
    }
};
