class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequencyMap;

        for(int num : nums) {
            frequencyMap[num]++;
        }

        vector<pair<int,int>> frequencyNumArr;
        for(const auto& [num,freq] : frequencyMap) {
            frequencyNumArr.push_back({freq,num});
        }

        sort(frequencyNumArr.rbegin(),frequencyNumArr.rend());

        vector<int> topKFrequent;
        for(int i=0; i<k; i++) {
            topKFrequent.push_back(frequencyNumArr[i].second);
        }

        return topKFrequent;
    }
};
