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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return head;
        } else if (head->next == NULL) {
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* inserted;

        while (temp->val <= temp->next->val) {
            temp = temp->next;
            if (temp->next == NULL) {
                return head;
            }
        }

        if (prev->val > temp->next->val) {
            inserted = new ListNode(temp->next->val);
            temp->next = temp->next->next;
            inserted->next = prev;
            return insertionSortList(inserted);
        }

        while (prev->next->val <= temp->next->val) {
            prev = prev->next;
        }

        inserted = new ListNode(temp->next->val);
        temp->next = temp->next->next;
        inserted->next = prev->next;
        prev->next = inserted;

        return insertionSortList(head);
    }
};
