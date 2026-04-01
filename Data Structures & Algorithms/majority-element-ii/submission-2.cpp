class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        for(auto& pair : freq) {
            if(pair.second > nums.size() / 3) {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};