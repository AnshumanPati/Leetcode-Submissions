/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void solve(Node* curr){
        if(curr == nullptr || curr->left == nullptr)
            return;
        
        curr->left->next = curr->right;
        if(curr->next == nullptr)
            curr->right->next = nullptr;
        else    
            curr->right->next = curr->next->left;
        solve(curr->left);
        solve(curr->right);
    }
public:
    Node* connect(Node* root) {
        Node* copy = root;
        solve(root);
        return copy;
    }
};