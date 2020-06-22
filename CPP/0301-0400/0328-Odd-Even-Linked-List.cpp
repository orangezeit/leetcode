/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* inserted = head;
        ListNode* temp = head;

        while (temp && temp->next && temp->next->next) {

            ListNode* slow = temp->next;
            ListNode* fast = temp->next->next;
            ListNode* temp2 = inserted->next;

            if (fast) {
                inserted->next = fast;
                slow->next = fast->next;
                fast->next = temp2;
            } else {
                inserted->next = slow;
                slow->next = temp2->next;
            }
            inserted = inserted->next;
            temp = slow;
        }
        return head;
    }
};
