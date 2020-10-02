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
public:
    enum STATUS {
        ROOT_NULL = 0x0,
        ROOT = 0x1,
        LEFT = 0x2,
        RIGHT = 0x4
    };
    void s_helper(TreeNode* root, ostringstream& out) {
        char status = 0;
        if (root) status |= ROOT;
        if (root && root->left) status |= LEFT;
        if (root && root->right) status |= RIGHT;
        out.write(&status, sizeof(char));
        if (!root) return;
        out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        if (root->left) s_helper(root->left, out);
        if (root->right) s_helper(root->right, out);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        s_helper(root, out);
        return out.str();
    }

    TreeNode* helper(istringstream& in) {
        char status;
        in.read(&status, sizeof(char));
        if (!status & ROOT) return NULL;
        TreeNode* root = new TreeNode(0);
        in.read(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        if (status & LEFT) root->left = helper(in);
        if (status & RIGHT) root->right = helper(in);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return helper(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
