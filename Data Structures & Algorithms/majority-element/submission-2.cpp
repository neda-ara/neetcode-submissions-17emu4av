class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> countMap;
        int majorityEl = -1; 
        int maxCount = 0;

        for(int num : nums) {
            countMap[num]++;

            if(countMap[num] > maxCount) {
                majorityEl = num;
                maxCount = countMap[num];
            }
        }

        return majorityEl;
    }
};