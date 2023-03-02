/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

private:
    TreeNode* deserializeHelper(stringstream& ss) {
        string str;
        getline(ss, str, ',');
        if (str == "null") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(str));
        node->left = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null,";
        }
        string str = to_string(root->val) + ",";
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null,") {
            return nullptr;
        }
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));