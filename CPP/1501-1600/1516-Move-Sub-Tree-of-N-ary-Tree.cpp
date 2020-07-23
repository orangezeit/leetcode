class Solution {
public:
    Node* moveSubTree(Node* root, Node* p, Node* q) {
        Node *pp, *pq, *dummy = new Node(0, {root});
        vector<Node*>::iterator pi, qi;
        bool p_over_q(false);
        function<void(Node*, bool)> dfs = [&](Node* r, bool f) {
            for (auto it = r->children.begin(); it != r->children.end(); ++it) {
                if (*it == p) {
                    pp = r;
                    pi = it;
                } else if (*it == q) {
                    pq = r;
                    qi = it;
                    p_over_q |= f;
                }
                dfs(*it, f || (*it == p));
            }
        };

        dfs(dummy, false);

        if (pp == q) return root;

        q->children.emplace_back(p);
        if (p_over_q) {
            *pi = q;
            pq->children.erase(qi);
        } else
            pp->children.erase(pi);
        return dummy->children[0];
    }
};
