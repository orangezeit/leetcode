/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
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

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) return NULL;

        TreeNode* tn = new TreeNode(root->val);

        if (!root->children.empty())
            tn->left = encode(root->children[0]);
        TreeNode* l = tn->left;
        for (int i = 1; i < root->children.size(); ++i) {
            l->right = encode(root->children[i]);
            l = l->right;
        }


        return tn;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) return NULL;
        Node* tn = new Node(root->val, vector<Node*>(0));
        TreeNode* curr = root->left;
        while (curr) {
            tn->children.push_back(decode(curr));
            curr = curr->right;
        }
        return tn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
