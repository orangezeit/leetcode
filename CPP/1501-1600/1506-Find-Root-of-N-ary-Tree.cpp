class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        int v(0);
        for (Node* n: tree) {
            v ^= n->val;
            for (Node* c: n->children)
                v ^= c->val;
        }
        for (Node* n: tree)
            if (n->val == v)
                return n;
        return nullptr;
    }
};
