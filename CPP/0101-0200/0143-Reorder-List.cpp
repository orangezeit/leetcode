class Solution {
public:
    ListNode* findMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* temp = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* mid = findMid(head);
        ListNode* l1 = head;
        ListNode* l2 = reverse(mid->next);
        mid->next = nullptr;
        while (l1 && l2) {
            ListNode* temp1 = l1->next;
            ListNode* temp2 = l2->next;
            l1->next = l2;
            l2->next = temp1;
            l1 = temp1;
            l2 = temp2;
        }
    }
};
