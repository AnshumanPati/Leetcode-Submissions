/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, long lo, long hi){
        if(root == nullptr)
            return true;
        if(root->val <= lo || root->val >= hi)
            return false;
        return solve(root->left, lo, root->val) && solve(root->right, root->val, hi);
    }
public:
    bool isValidBST(TreeNode* root) {

        long lo = LONG_MIN;
        long hi = LONG_MAX;

        return solve(root, lo, hi);
        
    }
};