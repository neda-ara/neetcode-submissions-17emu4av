class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char task : tasks) {
            count[task-'A']++;
        }

        priority_queue<int> maxheap;
        for(int cnt : count) {
            if(cnt > 0) {
                maxheap.push(cnt);
            }
        }

        int time = 0;
        queue<pair<int,int>> q;

        while(!maxheap.empty() || !q.empty()) {
            time++;

            if(maxheap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxheap.top() - 1;
                maxheap.pop();
                if(cnt > 0) {
                    q.push({cnt,time+n});
                }
            }

            if(!q.empty() && q.front().second == time) {
                maxheap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
