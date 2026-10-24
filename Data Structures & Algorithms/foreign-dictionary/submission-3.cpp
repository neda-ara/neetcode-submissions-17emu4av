class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        string result;

        for (const auto& word : words) {
            for (char ch : word) {
                adj[ch];
                indegree[ch] = 0;
            }
        }

        for (size_t i = 0; i < words.size() - 1; i++) {
            const string &w1 = words[i], &w2 = words[i + 1];
            size_t minLen = min(w1.length(), w2.length());

            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (size_t j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if(!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<int> q;
        for(auto& [ch,degree] : indegree) {
            if(degree == 0) {
                q.push(ch);
            }
        }

        while(!q.empty()) {
            char ch = q.front();
            q.pop();
            result += ch;

            for(char neighbor : adj[ch]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return result.size() == indegree.size() ? result : "";
    }
};
