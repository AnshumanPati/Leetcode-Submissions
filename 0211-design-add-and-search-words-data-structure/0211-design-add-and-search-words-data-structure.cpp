class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() : children(26, nullptr), isEndOfWord(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children[c-'a'] == nullptr) {
                curr->children[c-'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchWord(root, word, 0);
    }
    
    bool searchWord(TrieNode* node, string& word, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }
        char c = word[index];
        if (c != '.') {
            if (node->children[c-'a'] == nullptr) {
                return false;
            }
            return searchWord(node->children[c-'a'], word, index+1);
        } else {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr && searchWord(node->children[i], word, index+1)) {
                    return true;
                }
            }
            return false;
        }
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */