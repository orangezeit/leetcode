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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> rec; // pre-sum, node (most front)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        int sum(0);

        while (temp) {

            sum += temp->val;
            //cout << sum << endl;
            if (!rec.count(sum)) {
                rec[sum] = temp;

            } else {
                ListNode* n = rec[sum]->next;
                int s = sum + n->val;
                while (s != sum) {
                    rec.erase(s);
                    n = n->next;
                    s += n->val;
                }
                rec[sum]->next = n->next;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
