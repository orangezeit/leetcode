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
    
    int countNode(ListNode* n) {
        if (n == NULL) {
            return 0;
        }
        
        int num = 1;
        
        while (n->next != NULL) {
            num++;
            n = n->next;
        }
        
        return num;
    }
    
    ListNode* editNode(ListNode* large, ListNode* small) {
        ListNode* temp = large;

        while(small != NULL) {
            temp->val += small->val;
            
            if (temp->val < 10) {
                temp = temp->next;
            } else {
                temp->val %= 10;
                temp = temp->next;
                temp->val++;
            }
            
            small = small->next;
        }
        
        while (temp != NULL) {
            if (temp->val < 10) {
                temp = temp->next;
            } else {
                temp->val = 0;
                if (temp->next != NULL) {
                    temp = temp->next;
                    temp->val++;
                } else {
                    temp->next = new ListNode(1);
                }
            }
        }
        
        return large;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (countNode(l1) > countNode(l2)) {
            return reverse(editNode(reverse(l1), reverse(l2)));
        } else {
            return reverse(editNode(reverse(l2), reverse(l1)));
        }
    }
