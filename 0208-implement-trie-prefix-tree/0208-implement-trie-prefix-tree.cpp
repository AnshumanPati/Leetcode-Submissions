class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c-'a'] == NULL) {
                current->children[c-'a'] = new TrieNode();
            }
            current = current->children[c-'a'];
        }
        current->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children[c-'a'] == NULL) {
                return false;
            }
            current = current->children[c-'a'];
        }
        return current->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children[c-'a'] == NULL) {
                return false;
            }
            current = current->children[c-'a'];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */