class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num : nums) { // O(n)
            count[num]++;
        }

        int n = nums.size();
        vector<vector<int>> freq(n+1);

        for(auto c : count) { // O(d)
            freq[c.second].push_back(c.first);
        }

        vector<int> topK;
        for(int i=n; i>0; i--) {
            for(int n : freq[i]) {
                topK.push_back(n);
                if(topK.size() == k) {
                    return topK;
                }
            }
        }

        return topK;
    }
};
