class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int num : nums) {
            freq[num]++;

            if(freq.size() > 2) {
                unordered_map<int,int> newFreq;

                for(auto& entry : freq) {
                    if(entry.second > 1) {
                        newFreq[entry.first] = entry.second - 1;
                    }
                }
                freq = newFreq;
            }
        }

        vector<int> ans;
        for(auto& entry : freq) {
            int count = 0;

            for(int num : nums) {
                if(num == entry.first) count++;
            }
            if(count > nums.size() / 3) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};