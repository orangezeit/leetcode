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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return root ? to_string(root->val) + " " + serialize(root->left) + serialize(root->right) : "";
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        val < root->val ? root->left = root->left ? insertIntoBST(root->left, val) : new TreeNode(val)
                        : root->right = root->right ? insertIntoBST(root->right, val) : new TreeNode(val);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i(0);

        int k(0);
        TreeNode* tn=NULL;
        while (i < data.length()) {
            //cout << i << endl;
            while (data[i] != ' ') i++;
            if (tn)
                insertIntoBST(tn, stoi(data.substr(k, i++)));
            else
                tn = new TreeNode(stoi(data.substr(k, i++)));
            k = i;
            //cout << i;
        }
        return tn;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
