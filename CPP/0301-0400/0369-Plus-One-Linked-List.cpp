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
    ListNode* reverse(ListNode* head) {
        ListNode* next;
        ListNode* current = head;
        ListNode* prev = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
        return head;
    }

    ListNode* addOne(ListNode* head) {
        ListNode* temp = head;
        temp->val++;
        while(temp->val > 9) {
            temp->val %= 10;
            if (!temp->next) {
                temp->next = new ListNode(0);
            }
            temp = temp->next;
            temp->val++;
        }
        return head;
    }

    ListNode* plusOne(ListNode* head) {
        return reverse(addOne(reverse(head)));
    }
};
