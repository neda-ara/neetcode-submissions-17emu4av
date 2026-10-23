class Solution {
    unordered_map<char,unordered_set<char>> adj;
    unordered_map<char,bool> exploring;
    string result;

public:
    string foreignDictionary(vector<string>& words) {
        for(const auto& word : words) {
            for(char ch : word) {
                adj[ch];
            }
        }

        for(size_t i=0; i<words.size()-1; i++) {
            const string& w1 = words[i], & w2 = words[i+1];
            size_t minLen = min(w1.length(), w2.length());

            if(w1.length() > w2.length() && w1.substr(0,minLen) == w2.substr(0,minLen)) {
                return "";
            }
            for(size_t j=0; j<minLen; j++) {
                if(w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for(const auto& [ch,_] : adj) {
            if(hasCycle(ch)) {
                return "";
            }
        }

        reverse(result.begin(),result.end());
        return result;
    }

    bool hasCycle(char ch) {
        if(exploring.count(ch)) {
            return exploring[ch];
        }

        exploring[ch] = true;

        for(char next : adj[ch]) {
            if(hasCycle(next)) {
                return true;
            }
        }

        exploring[ch] = false;
        result += ch;
        return false;
    }
};
