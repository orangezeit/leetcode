/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool notDigit(char n) {
        return n < '0' || n > '9';
    }

    TreeNode* helper(string s, int dash) {


        int k = 0;
        while (s[++k] != '-') {
            if (k == s.length()) return new TreeNode(stoi(s));
        }

        TreeNode* n = new TreeNode(stoi(s.substr(0, k)));

        while (s[++k] == '-') {}

        int d = k;
        if (d + dash >= s.length()) {
            n->left = helper(s.substr(k, s.length() - k), dash + 1);
            n->right = NULL;
            return n;
        }

        while (notDigit(s[d-1]) || notDigit(s[d+dash]) || s.substr(d,dash) != string(dash, '-')) {

            d++;
            if (d+dash == s.length()) {
                n->left = helper(s.substr(k, s.length() - k), dash + 1);
                n->right = NULL;
                return n;
            }
        }

        n->left = helper(s.substr(k, d-k), dash + 1);
        n->right = helper(s.substr(d+dash, s.length()-d-dash), dash + 1);
        return n;
    }

    TreeNode* recoverFromPreorder(string S) {
        return helper(S, 1);
    }
};
