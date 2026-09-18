class TrieNode {
public:
    unordered_map<char,TrieNode*> children;
    bool word;

    TrieNode(): word(false) {};

    void addWord(const string& word) {
        TrieNode* curr = this;
        for(char c : word) {
            if(!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->word = true;
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

        for(int r=0; r<board.size(); r++) {
            for(int c=0; c<board[0].size(); c++) {
                string word = "";
                dfs(board,r,c,root,word);
            }
        }

        return vector<string>(res.begin(),res.end());
    }

private:
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string& word) {
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] == '*' || !node->children.count(board[r][c])) {
            return;
        }

        char temp = board[r][c];
        board[r][c] = '*';

        node = node->children[temp];
        word += temp;
        if(node->word) {
            res.insert(word);
        }

        dfs(board,r+1,c,node,word);
        dfs(board,r-1,c,node,word);
        dfs(board,r,c+1,node,word);
        dfs(board,r,c-1,node,word);

        word.pop_back();
        board[r][c] = temp;
    }
};
