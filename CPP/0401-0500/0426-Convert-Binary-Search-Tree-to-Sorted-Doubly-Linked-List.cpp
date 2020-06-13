/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* prev;
    void traverse(Node* root) {
        if (!root) return;
        traverse(root->left);
        prev->right = root;
        root->left = prev;
        prev = root;
        traverse(root->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        Node* dummy = new Node(0, nullptr, nullptr);
        prev = dummy;
        traverse(root);
        //cout << prev->val << endl;
        prev->right = dummy->right;
        dummy->right->left = prev;
        return dummy->right;
    }
};
