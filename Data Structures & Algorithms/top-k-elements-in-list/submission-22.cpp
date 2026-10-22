class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> mh;
        for (auto& [num, fre] : freq) {
            mh.push({fre, num});
            if(mh.size() > k) {
                mh.pop();
            } 
        }

        vector<int> topK;
        while(mh.size()) {
            topK.push_back(mh.top().second);
            mh.pop();
        }

        return topK;
    }
};
