class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for(char& task : tasks) {
            cnt[task-'A']++;
        }   

        int maxf = *max_element(cnt.begin(),cnt.end());
        int maxCount = 0;

        for(int i : cnt) {
            if(i == maxf) {
                maxCount++;
            }
        }

        int time = (maxf-1)*(n+1) + maxCount;

        return max((int) tasks.size(),time);
    }
};
