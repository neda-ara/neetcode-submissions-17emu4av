class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        for(int num : nums) { // O(n)
            frequency[num]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> minHeap;

        for(auto [num,freq] : frequency) {
            minHeap.push({freq,num}); // O(log(k+1))
            if(minHeap.size() > k) {
                minHeap.pop(); // O(log(k+1))
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
