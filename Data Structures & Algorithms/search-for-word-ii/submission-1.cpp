class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool isWord;

    TrieNode(): isWord(false) {};

    void addWord(const string& word) {
        TrieNode* curr = this;
        for(char c : word) {
            if(!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(const string& word : words) {
            root->addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();

        for(int r=0; r<ROWS; r++) {
            for(int c=0; c<COLS; c++) {
                string word = "";
                dfs(board, r, c, root, word);
            }
        }
        return vector<string> (res.begin(),res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string& word) {
        int ROWS = board.size(), COLS = board[0].size();
        
        if(r<0 || c<0 || r>=ROWS || c>=COLS || !node->children.count(board[r][c]) || board[r][c] == '*') {
            return;
        }

        char temp = board[r][c];
        node = node->children[board[r][c]];
        word.push_back(board[r][c]);
        if(node->isWord) {
            res.insert(word);
        }
        board[r][c] = '*';

        dfs(board,r+1,c,node,word);
        dfs(board,r-1,c,node,word);
        dfs(board,r,c+1,node,word);
        dfs(board,r,c-1,node,word);

        board[r][c] = temp;
        word.pop_back();
    }
};
