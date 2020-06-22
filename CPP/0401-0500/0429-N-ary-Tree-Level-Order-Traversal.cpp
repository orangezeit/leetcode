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
class Solution {
private:
    vector<vector<int>> orders;

    void record(Node* root, int level) {
        if (root == NULL) return;
        orders.size() == level ? orders.push_back({root->val}) : orders[level].push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i)
            record(root->children[i], level + 1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        record(root, 0);
        return orders;
    }
};
