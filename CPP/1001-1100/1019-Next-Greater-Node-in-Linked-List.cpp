/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        // monotonic stack
        vector<int> ans;

        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }

        stack<int> s;

        for (int i = ans.size() - 1; i >= 0; --i) {
            int greater = 0;

            if (!s.empty()) {
                bool test = true;
                while (s.top() <= ans[i]) {
                    s.pop();
                    if (s.empty()) {
                        test = false;
                        break;
                    }
                }

                if (test) greater = s.top();
            }
            s.push(ans[i]);
            ans[i] = greater;
        }
        return ans;
    }
};
