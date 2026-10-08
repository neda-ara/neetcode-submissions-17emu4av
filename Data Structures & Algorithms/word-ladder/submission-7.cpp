class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(!words.count(endWord) || beginWord == endWord || endWord.empty() || wordList.empty()) {
            return 0;
        }

        unordered_map<string,vector<string>> nei;
        wordList.push_back(beginWord);

        for(const string& word : wordList) {
            for(int j=0; j<word.size(); j++) {
                string pattern = word.substr(0, j) + "*" + word.substr(j+1);
                nei[pattern].push_back(word);
            }
        }

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while(!q.empty()) {
            int sz = q.size();

            for(int i=0; i<sz; i++) {
                string node = q.front();
                q.pop();

                for(int j=0; j<node.size(); j++) {
                    string pattern = node.substr(0, j) + "*" + node.substr(j+1);

                    for(const string& neiWord : nei[pattern]) {
                        if(words.count(neiWord)) {
                            if(neiWord == endWord) {
                                return steps+1;
                            }
                            words.erase(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            steps++;
        }

        return 0;
    }
};
