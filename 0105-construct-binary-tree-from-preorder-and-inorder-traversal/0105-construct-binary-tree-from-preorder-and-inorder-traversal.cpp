class Solution {

private:
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>& inorderMap, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd) {
        if (preorderStart > preorderEnd || inorderStart > inorderEnd) {
            return nullptr;
        }
        int rootVal = preorder[preorderStart];
        int rootIndexInorder = inorderMap[rootVal];
        int numNodesLeftSubtree = rootIndexInorder - inorderStart;
        TreeNode* root = new TreeNode(rootVal);

        root->left = buildTreeHelper(preorder, inorderMap, preorderStart + 1, 
            preorderStart + numNodesLeftSubtree, inorderStart, rootIndexInorder - 1);

        root->right = buildTreeHelper(preorder, inorderMap, preorderStart + numNodesLeftSubtree + 1, 
            preorderEnd, rootIndexInorder + 1, inorderEnd);
            
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorderMap, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
