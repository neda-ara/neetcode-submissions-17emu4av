class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {
            sort(stones.begin(),stones.end());
            int first = stones.back();
            int second = stones[stones.size() - 2];
            stones.pop_back();
            stones.pop_back();
            
            if(first-second > 0) {
                stones.push_back(first-second);
            }
        }

        return stones.empty() ? 0 : stones[0];
    }
};
