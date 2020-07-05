/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool test(ListNode* head, TreeNode* root) {
        if (!head) return true;
        if (!root) return false;
        return head->val == root->val && (test(head->next, root->left) || test(head->next, root->right));
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return test(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
