/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right) {
            node = node->right;
            while(node->left)
                node = node->left;
        } else {
            int val = node->val;
            while (node && node->val <= val)
                node = node->parent;
        }
        return node;
    }
};
