class TrieNode {
public:
    vector<TrieNode*> children;
    int idx;
    int refs;

    TrieNode(): children(26,nullptr), idx(-1), refs(0) {};

    void addWord(const string& word, int index) {
        TrieNode* curr = this;
        curr->refs++;

        for(char c : word) {
            int i = c-'a';
            if(!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
            curr->refs++;
        }
        curr->idx = index;
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

        int ROWS = board.size(), COLS = board[0].size();

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                root->refs -= dfs(board,r,c,root,words);
            }
        }
        return res;
    }

private:
    int dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& words) {
        int ROWS = board.size(), COLS = board[0].size();
        
        if(r<0 || c<0 || r>=ROWS || c>=COLS || !node->children[board[r][c]-'a'] || board[r][c] == '*') {
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
        

        found += dfs(board,r+1,c,node,words);
        found += dfs(board,r-1,c,node,words);
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
