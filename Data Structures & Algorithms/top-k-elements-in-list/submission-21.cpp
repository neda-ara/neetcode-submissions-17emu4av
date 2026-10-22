class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        vector<pair<int,int>> arr;
        for(auto& [num,fre] : freq) {
            arr.push_back({fre,num});
        }

        sort(arr.rbegin(),arr.rend());

        vector<int> topK;
        for(int i=0; i<k; i++) {
            topK.push_back(arr[i].second);
        }

        return topK;
    }
};
