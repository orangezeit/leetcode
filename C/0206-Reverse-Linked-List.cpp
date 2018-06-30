    ListNode* reverseList(ListNode* head) {
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
