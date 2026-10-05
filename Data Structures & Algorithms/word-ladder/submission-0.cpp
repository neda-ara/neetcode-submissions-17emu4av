class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord) == wordList.end() || beginWord == endWord) {
            return 0;
        }

        int n = wordList.size(), m = wordList[0].size();

        unordered_map<string,int> wordToIdx;
        for(int i=0; i<n; i++) {
            wordToIdx[wordList[i]] = i;
        }

        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int cnt = 0;
                for(int k=0; k<m; k++) {
                    if(wordList[i][k] != wordList[j][k]) {
                        cnt++;
                    }
                }
                if (cnt == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ladder_length = 1;

        queue<int> q;
        unordered_set<int> visit;
        
        for(int i=0; i<m; i++) {
            for(char c='a'; c<='z'; c++) {
                if(c == beginWord[i]) {
                    continue;
                }
                string word = beginWord.substr(0,i) + c + beginWord.substr(i+1);

                if(wordToIdx.count(word) && !visit.count(wordToIdx[word])) {
                    q.push(wordToIdx[word]);
                    visit.insert(wordToIdx[word]);
                }

            }
        }

        while(!q.empty()) {
            ladder_length++;
            int size = q.size();

            for(int i=0; i<size; i++) {
                int node = q.front();
                q.pop();

                if(wordList[node] == endWord) {
                    return ladder_length;
                }
                for(int nei : adj[node]) {
                    if(!visit.count(nei)) {
                        visit.insert(nei);
                        q.push(nei);
                    }
                }
            }
        }

        return 0;
    }
};
