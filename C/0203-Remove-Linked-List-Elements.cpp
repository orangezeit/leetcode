    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* temp = head;
        
        while(temp != NULL && temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        
        if (head->val == val) {
            head = head->next;
        }
        
        return head;
    }
