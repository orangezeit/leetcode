/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (!root) return nullptr;

        unordered_map<Node*,NodeCopy*> mp;
        NodeCopy* rt = mp[root] = new NodeCopy(root->val);
        queue<Node*> q({root});

        while (!q.empty()) {
            Node* r = q.front();
            q.pop();
            if (r->left) {
                q.push(r->left);
                mp[r]->left = mp[r->left] = new NodeCopy(r->left->val);
            }
            if (r->right) {
                q.push(r->right);
                mp[r]->right = mp[r->right] = new NodeCopy(r->right->val);
            }
        }

        for (auto&[k, v]: mp)
            if (mp.count(k->random))
                v->random = mp[k->random];

        return rt;
    }
};
