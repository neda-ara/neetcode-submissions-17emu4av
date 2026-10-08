class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(!words.count(endWord) || beginWord == endWord || endWord.empty() || wordList.empty()) {
            return 0;
        }

        int n = wordList.size(), m = wordList[0].size();
        unordered_map<string,int> wordIdx;

        for(int i=0; i<n; i++) {
           wordIdx[wordList[i]] = i; 
        }

        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int diff = 0;

                for(int k=0; k<m; k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        diff++;
                    }
                }

                if(diff == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int> q;
        int steps = 1;

        for(int i=0; i<m; i++) {
            for(char c='a'; c<='z'; c++) {
                if(c == beginWord[i]) {
                    continue;
                }
                string word = beginWord.substr(0,i) + c + beginWord.substr(i+1);
                if(wordIdx.count(word) && words.count(word)) {
                    q.push(wordIdx[word]);
                    words.erase(word);
                }
            }
        }

        while(!q.empty()) {
            steps++;
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                int node = q.front();
                q.pop();

                if(wordList[node] == endWord) {
                    return steps;
                }

                for(int nei : adj[node]) {
                    if(words.count(wordList[nei])) {
                        words.erase(wordList[nei]);
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    }
};
