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
    TreeNode* str2tree(string s) {
        if (s.empty())
            return NULL;

        if (s.back() != ')')
            return new TreeNode(stoi(s));

        int val;
        int k;
        stack<char> brackets;
        brackets.push('(');

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                val = stoi(s.substr(0,i+1));
                k = i + 1;
                break;
            }
        }

        TreeNode* n = new TreeNode(val);

        for (int i = k; i < s.length(); ++i) {
            if (s[i] == '(') {
                brackets.push(s[i]);
            } else if (s[i] == ')') {
                brackets.pop();
            }

            if (brackets.empty()) {
                n->left = str2tree(s.substr(k, i-k));
                //cout << i+2 << endl;
                if (i+1 == s.length()) {
                    n->right = NULL;
                } else {
                    n->right = str2tree(s.substr(i+2, s.length()-i-3));
                }

                break;
            }
        }

        return n;
    }
};
