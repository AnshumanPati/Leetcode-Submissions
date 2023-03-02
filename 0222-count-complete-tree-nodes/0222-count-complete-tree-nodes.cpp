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
    
    int findDepth(TreeNode* node){
        int d = 0;
        while(node->left != nullptr){
            node = node->left;
             d++;
        }
        return d;
    }
    
    bool exists(int idx, int d, TreeNode* root){
        int left = 0, right = (1<<d)-1;//pow(2,d) - 1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(idx<=mid){
                root = root->left;
                right = mid;
            }
            else{
                root = root->right;
                left = mid+1;
            }
        }
        return root!=nullptr;
    }
    
public:
    int countNodes(TreeNode* root) {
    
        if(root == nullptr)
            return 0;
        
        
        int d = findDepth(root);
        
        if(d==0)
            return 1;
        
        int left = 1, right = (1<<d) - 1;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(exists(mid,d,root)){
                left = mid+1;
            }
            else
                right = mid-1;
        }
        
        return (1<<d)-1+left;
        
    }
};