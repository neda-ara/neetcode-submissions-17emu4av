class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        for(int num : nums) {
            frequency[num]++;
        }   

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> minHeap;

        for(auto [num,freq] : frequency) {
            minHeap.push({freq,num});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> topK;
        for(int i=0; i<k; i++) {
            topK.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return topK;
    }
};
