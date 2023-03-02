/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(p->val < root->val && q->val < root->val)
            return solve(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return solve(root->right, p, q);
        else
            return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q)
            return p;
        return solve(root, p, q);
    }
};