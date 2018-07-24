    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* temp = head;
        ListNode* prev = dummyHead;
        
        while(temp && temp->next) {
            if (temp->val == temp->next->val) {
                while(temp->val == temp->next->val) {
                    ListNode* repeated = temp->next;
                    temp->next = temp->next->next;
                    delete repeated;
                    
                    if (temp->next == NULL) {
                        break;
                    }
                }
                
                ListNode* repeated = prev->next;
                prev->next = prev->next->next;
                delete repeated;
                
                temp = prev->next;
                if (temp == NULL) {
                    break;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        head = dummyHead->next;
        delete dummyHead, temp, prev;
        return head;
    }
