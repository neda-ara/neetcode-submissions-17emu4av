class TrieNode {
public:
    vector<TrieNode*> children;
    int idx;
    int refs;

    TrieNode(): children(26,nullptr), idx(-1), refs(0) {};

    void addWord(const string& word, int i) {
        TrieNode* curr = this;
        curr->refs++;
        for(char c : word) {
            if(!curr->children[c-'a']) {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
            curr->refs++;
        }
        curr->idx = i;
    }
};

class Solution {
    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i=0; i<words.size(); i++) {
            root->addWord(words[i],i);
        }

        for(int r=0; r<board.size(); r++) {
            for(int c=0; c<board[0].size(); c++) {
                root->refs -= dfs(board,r,c,root,words);
            }
        }

        return res;
    }

private:
    int dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& words) {
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] == '*' || !node->children[board[r][c]-'a']) {
            return 0;
        }

        char temp = board[r][c];
        board[r][c] = '*';

        TrieNode* prev = node;
        node = node->children[temp-'a'];

        int found = 0;
        if(node->idx != -1) {
            res.push_back(words[node->idx]);
            node->idx = -1;
            found++;
        }

        found += dfs(board,r-1,c,node,words);
        found += dfs(board,r+1,c,node,words);
        found += dfs(board,r,c+1,node,words);
        found += dfs(board,r,c-1,node,words);

        board[r][c] = temp;
        node->refs -= found;
        if(!node->refs) {
            prev->children[temp-'a'] = nullptr;
        }
        return found;
    }
};
