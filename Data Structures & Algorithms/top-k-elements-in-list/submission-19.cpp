class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequencyMap;

        for(int num : nums) {
            frequencyMap[num]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> 
        minHeap;

        for(const auto& [num,freq] : frequencyMap) {
            minHeap.push({freq,num});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> topKFrequent;
        for(int i=0; i<k; i++) {
            topKFrequent.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topKFrequent;
    }
};
