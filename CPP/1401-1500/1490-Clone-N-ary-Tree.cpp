/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return nullptr;
        Node* t = new Node(root->val);
        int n = root->children.size();
        t->children.resize(n);
        for (int i = 0; i < n; ++i)
            t->children[i] = cloneTree(root->children[i]);
        return t;
    }
};
