class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(!words.count(endWord) || beginWord == endWord || endWord.empty() || wordList.empty()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int steps = 0;

        while(!q.empty()) {
            steps++;
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                string node = q.front();
                q.pop();

                for(int j=0; j<node.size(); j++) {
                    char original = node[j];
                    for(char c='a'; c<='z'; c++) {
                        if(c == original) {
                            continue;
                        }
                        node[j] = c;
                        if(words.count(node)) {
                            if(node == endWord) {
                                return steps+1;
                            }
                            q.push(node);
                            words.erase(node);
                        }
                    }
                    node[j] = original;
                }
            }
        }

        return 0;
    }
};
