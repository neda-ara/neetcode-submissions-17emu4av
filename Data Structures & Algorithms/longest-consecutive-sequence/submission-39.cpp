class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_len = 0;
        unordered_map<int,int> seq;

        for(int num : nums) {
            if(!seq[num]) {
                seq[num] = seq[num-1] + 1 + seq[num+1];
                seq[num - seq[num-1]] = seq[num];
                seq[num + seq[num+1]] = seq[num];
                max_len = max(max_len,seq[num]); 
            }  
        }

        return max_len;
    }
};
