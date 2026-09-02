class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1) {
            sort(stones.begin(),stones.end());
            
            int first = stones.back();
            stones.pop_back();
            int second = stones.back();
            stones.pop_back();

            int diff = first - second;
            if(diff > 0) {
                stones.push_back(diff);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};
