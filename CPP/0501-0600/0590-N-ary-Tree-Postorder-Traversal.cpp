/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void postorderHelper(Node* root, vector<int>& post) {
        if (!root) {
            return;
        }
        for (int i = 0; i < root->children.size(); ++i) {
            postorderHelper(root->children[i], post);
        }
        post.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> post;
        postorderHelper(root, post);
        return post;
    }
};
