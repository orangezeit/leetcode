/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* helper(Node* node, unordered_map<Node*, Node*>& m ) {
        if (!node) return NULL;
        if (m.find(node) != m.end()) return m[node];
        Node* n = new Node();
        n->val = node->val;
        m[node] = n;
        n->neighbors.resize(node->neighbors.size());
        for (int i = 0; i < node->neighbors.size(); ++i)
            n->neighbors[i] = helper(node->neighbors[i], m);
        return n;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> m;
        return helper(node, m);
    }
};
