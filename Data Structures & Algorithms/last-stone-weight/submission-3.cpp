class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int max_weight = stones[0];
        for(int stone : stones) {
            max_weight = max(max_weight,stone);
        }

        vector<int> buckets(max_weight+1,0);
        for(int stone : stones) {
            buckets[stone]++;
        }

        int first = max_weight, second = max_weight;
        
        while(first > 0) {
            if(buckets[first] % 2 == 0) {
                first--;
                continue;
            }

            int j = min(first-1,second);
            while(j > 0 && buckets[j] == 0) {
                j--;
            }

            if(j==0) {
                return first;
            }

            second = j;
            buckets[first]--;
            buckets[second]--;
            buckets[first-second]++;
            first = max(first-second,second);
        }
        return first;
    }
};
