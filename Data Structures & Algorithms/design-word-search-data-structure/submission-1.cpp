class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26,nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() : root(new TrieNode()) {}
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(const char& c : word) {
            int i = c - 'a';
            if(!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word,0,root);
    }

private:
    bool dfs(string& word, int i, TrieNode* root) {
        TrieNode* curr = root;

        while(i < word.length()) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* child : curr->children) {
                    if(child && dfs(word,i+1,child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if(!curr->children[c-'a']) {
                    return false;
                }
                curr = curr->children[c-'a'];
            }
            i++;
        }
        return curr->word;
    }
};
