    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        
        while(temp && temp->next) {
            if (temp->val == temp->next->val) {
                ListNode* repeated = temp->next;
                temp->next = temp->next->next;
                delete repeated;
            } else {
                temp = temp->next;
            }
        }
        
        return head;
    }
