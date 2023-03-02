class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode() : children(26, nullptr), isWord(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {}
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c-'a'] == nullptr)
                node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string word : words)
            trie.insert(word);
        
        vector<string> res;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                searchWords(board, i, j, visited, trie.root, "", res);
            }
        }
        return res;
    }
    
    void searchWords(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, 
                                            TrieNode* node, string word, vector<string>& res) {
        if (node->isWord) {
            res.push_back(word);
            node->isWord = false;  // mark as found to avoid duplicates
        }
        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || node->children[board[i][j]-'a'] == nullptr)
            return;
        
        visited[i][j] = true;
        searchWords(board, i+1, j, visited, node->children[board[i][j]-'a'], word+board[i][j], res);
        searchWords(board, i-1, j, visited, node->children[board[i][j]-'a'], word+board[i][j], res);
        searchWords(board, i, j+1, visited, node->children[board[i][j]-'a'], word+board[i][j], res);
        searchWords(board, i, j-1, visited, node->children[board[i][j]-'a'], word+board[i][j], res);
        visited[i][j] = false;
    }
};
