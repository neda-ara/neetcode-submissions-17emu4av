class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(!words.count(endWord) || beginWord == endWord || endWord.empty() || wordList.empty()) {
            return 0;
        }

        queue<string> qb, qe;
        unordered_map<string,int> fromBegin, fromEnd;

        qb.push(beginWord);
        qe.push(endWord);

        fromBegin[beginWord] = 1;
        fromEnd[endWord] = 1;

        while(!qb.empty() && !qe.empty()) {
            if(qb.size() > qe.size()) {
                swap(qb,qe);
                swap(fromBegin,fromEnd);
            }

            int size = qb.size();
            
            for(int i=0; i<size; i++) {
                string node = qb.front();
                qb.pop();

                int steps = fromBegin[node];

                for(int j=0; j<node.size(); j++) {
                    for(char c='a'; c<='z'; c++) {
                        if(c == node[j]) {
                            continue;
                        }

                        string nei = node.substr(0, j) + c + node.substr(j+1);

                        if(!words.count(nei)) {
                            continue;
                        }
                        if(fromEnd.count(nei)) {
                            return steps + fromEnd[nei];
                        }
                        if(!fromBegin.count(nei)) {
                            fromBegin[nei] = steps+1;
                            qb.push(nei);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
