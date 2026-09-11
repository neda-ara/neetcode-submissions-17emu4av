class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        vector<pair<int,int>> arr;
        for(auto [num,f] : freq) {
            arr.push_back({f,num});
        }

        sort(arr.rbegin(),arr.rend());

        vector<int> answer;
        for(int i=0; i<k; i++) {
            answer.push_back(arr[i].second);
        }

        return answer;
    }
};
